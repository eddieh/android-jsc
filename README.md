# JavaScriptCore for Android

This is a minimalist variant of JavaScriptCore for embedding in Android
apps. Typically JavaScriptCore is prohibitively large and not easily
embedded. This project aims to create a minimalist variant of
JavaScriptCore that can be embedded in an app without significantly
increasing the app size.

Currently our variant of JavaScriptCore is 742KB.


## Quick Start

1. Install and configure the Android SDK & NDK.
2. With a device attached, run:

```
$ make installd
```

Or without a device attached, run:

```
$ make build
```


## Approach

JavaScriptCore traditionally uses ICU for Unicode support. ICU is huge
and dominates the size of the JavaScriptCore binary. By not including
ICU we can gain a significant size reduction, but we must at the very
least provide some dummy functionality for Unicode.

Eventually we will have full Unicode support as required by the
ECMAScript specification.


## Copyright and License

JavaScriptCore is licensed under the LGPL. The build scripts are
derived from the Android Open Source Project and are licensed under
Apache License 2.0.
