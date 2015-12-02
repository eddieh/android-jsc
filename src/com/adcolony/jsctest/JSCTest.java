/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.adcolony.jsctest;

import android.app.Activity;
import android.widget.TextView;
import android.os.*;
import android.util.*;
import java.io.*;
import java.util.*;

public class JSCTest extends Activity
{
    byte[] loadAsset(String asset)
    {
        if (asset == null) return null;

        try {
            InputStream instream = getAssets().open(asset);
            ByteArrayOutputStream buffer = new ByteArrayOutputStream(instream.available());
            for (int ch = instream.read(); ch != -1; ch = instream.read()) {
                buffer.write(ch);
            }

            return buffer.toByteArray();
        } catch (IOException err) {
            Log.e("JSCTest", "Asset file not found: " + asset);
            return null;
        }
    }

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        /* Create a TextView and set its content.
         * the text is retrieved by calling a native
         * function.
         */
        TextView tv = new TextView(this);
        //tv.setText(stringFromJSC());
        //tv.setText(runTest("var test = function () { return 'Hello from runTest!\\n' }".getBytes()));

        // TODO: cumulative pass/fail count
        // NOTE: results cannot begin or end with white space
        try {
          String[] assets = this.getAssets().list("");

          // filter the list
          List<String> tests = new ArrayList<String>();
          for (String file : assets) {
            if (file.endsWith(".js")) tests.add(file);
          }

          String str = "";
          for (String testFile : tests) {
            // read the test.js
            byte[] testScript = this.loadAsset(testFile);

            // drop .js and add .expected from filename
            String expectedFile = testFile.replaceAll(".js", "");
            expectedFile = expectedFile += ".expected";

            // read the test.expected
            String expectedResults = (new String(this.loadAsset(expectedFile), "UTF-8")).trim();

            // run the test
            String testResults = this.runTest(testScript).trim();

            Log.e("JSCTest", "testResult: " + testResults);
            Log.e("JSCTest", "expectedResult: " + expectedResults);

            // compare the actual result with the expected result
            if (testResults.equals(expectedResults)) {
              str += testFile += " PASS\n";
            } else {
              str += testFile += " FAIL\n";
            }
          }

          tv.setText(str);
        } catch (IOException e) {}

        this.setContentView(tv);
    }

    /* A native method that is implemented by the
     * 'jsctest' native library, which is packaged
     * with this application.
     */
    public native String stringFromJNI();

    /* A native method that is implemented by the
     * 'jsctest' native library, which is packaged
     * with this application. This one uses JSC to
     * create a string.
     */
    public native String stringFromJSC();

    public native String runTest(byte[] src);

    /* this is used to load the 'jsctest' library on application
     * startup. The library has already been unpacked into
     * /data/data/com.adcolony.jsctest/lib/libjsctest.so at
     * installation time by the package manager.
     */
    static {
      System.loadLibrary("js");
      System.loadLibrary("jsctest");
    }
}
