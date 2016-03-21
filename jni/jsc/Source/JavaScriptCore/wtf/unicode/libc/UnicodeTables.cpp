/*
 * Copyright (C) 2016 Eddie Hillenbrand. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"

#if USE(LIBC_UNICODE)

namespace WTF {
namespace Unicode {

uint32_t UpperTable[865] = {
    11862940u, 14680256u, 14745793u, 14811330u, 14876867u, 14942404u,
    15007941u, 15073478u, 15139015u, 15204552u, 15270089u, 15335626u,
    15401163u, 15466700u, 15532237u, 15597774u, 15663311u, 15728848u,
    15794385u, 15859922u, 15925459u, 15990996u, 16056533u, 16122070u,
    16253144u, 16318681u, 16384218u, 16449755u, 16515292u, 16580829u,
    16646366u, 16712056u, 16843008u, 16974082u, 17105156u, 17236230u,
    17367304u, 17498378u, 17629452u, 17760526u, 17891600u, 18022674u,
    18153748u, 18284822u, 18415896u, 18546970u, 18678044u, 18809118u,
    18940192u, 19071266u, 19202340u, 19333414u, 19464488u, 19595562u,
    19726636u, 19857710u, 19988553u, 20119858u, 20250932u, 20382006u,
    20578617u, 20709691u, 20840765u, 20971839u, 21102913u, 21233987u,
    21365061u, 21496135u, 21692746u, 21823820u, 21954894u, 22085968u,
    22217042u, 22348116u, 22479190u, 22610264u, 22741338u, 22872412u,
    23003486u, 23134560u, 23265634u, 23396708u, 23527782u, 23658856u,
    23789930u, 23921004u, 24052078u, 24183152u, 24314226u, 24445300u,
    24576374u, 24772985u, 24904059u, 25035133u, 25100371u, 25166403u,
    25362818u, 25493892u, 25690503u, 25952651u, 26345873u, 26542582u,
    26804632u, 26870333u, 27132448u, 27328928u, 27460002u, 27591076u,
    27787687u, 28115372u, 28311983u, 28574131u, 28705205u, 28901816u,
    29163964u, 29295095u, 29688260u, 29753796u, 29884871u, 29950407u,
    30081482u, 30147018u, 30278093u, 30409167u, 30540241u, 30671315u,
    30802389u, 30933463u, 31064537u, 31195611u, 31261070u, 31392222u,
    31523296u, 31654370u, 31785444u, 31916518u, 32047592u, 32178666u,
    32309740u, 32440814u, 32637425u, 32702961u, 32834036u, 33096184u,
    33227258u, 33358332u, 33489406u, 33620480u, 33751554u, 33882628u,
    34013702u, 34144776u, 34275850u, 34406924u, 34537998u, 34669072u,
    34800146u, 34931220u, 35062294u, 35193368u, 35324442u, 35455516u,
    35586590u, 35848738u, 35979812u, 36110886u, 36241960u, 36373034u,
    36504108u, 36635182u, 36766256u, 36897330u, 37487163u, 37880385u,
    38208070u, 38339144u, 38470218u, 38601292u, 38732366u, 38994305u,
    39059846u, 39190921u, 39256458u, 39387535u, 39518608u, 39846291u,
    40042900u, 40370583u, 40436118u, 40578146u, 40829340u, 41025949u,
    41222559u, 41757796u, 41943462u, 42140073u, 42467758u, 42533444u,
    42598833u, 42664370u, 42730053u, 43123127u, 54854553u, 58393597u,
    58459134u, 58524671u, 61604742u, 61670280u, 61735817u, 61801354u,
    61932433u, 61997970u, 62063507u, 62129044u, 62194581u, 62260118u,
    62325655u, 62391192u, 62456729u, 62522266u, 62587803u, 62653340u,
    62718877u, 62784414u, 62849951u, 62915488u, 62981025u, 63046563u,
    63112099u, 63177636u, 63243173u, 63308710u, 63374247u, 63439784u,
    63505321u, 63570858u, 63636395u, 63701900u, 63767438u, 63832975u,
    63964050u, 64029592u, 64291750u, 64357280u, 64553944u, 64685018u,
    64816092u, 64947166u, 65078240u, 65209314u, 65340388u, 65471462u,
    65602536u, 65733610u, 65864684u, 65995758u, 66061210u, 66126753u,
    66192377u, 66388885u, 66585591u, 66782202u, 70255632u, 70321169u,
    70386706u, 70452243u, 70517780u, 70583317u, 70648854u, 70714391u,
    70779928u, 70845465u, 70911002u, 70976539u, 71042076u, 71107613u,
    71173150u, 71238687u, 71304224u, 71369761u, 71435298u, 71500835u,
    71566372u, 71631909u, 71697446u, 71762983u, 71828520u, 71894057u,
    71959594u, 72025131u, 72090668u, 72156205u, 72221742u, 72287279u,
    72352768u, 72418305u, 72483842u, 72549379u, 72614916u, 72680453u,
    72745990u, 72811527u, 72877064u, 72942601u, 73008138u, 73073675u,
    73139212u, 73204749u, 73270286u, 73335823u, 73466976u, 73598050u,
    73729124u, 73860198u, 73991272u, 74122346u, 74253420u, 74384494u,
    74515568u, 74646642u, 74777716u, 74908790u, 75039864u, 75170938u,
    75302012u, 75433086u, 75564160u, 76219530u, 76350604u, 76481678u,
    76612752u, 76743826u, 76874900u, 77005974u, 77137048u, 77268122u,
    77399196u, 77530270u, 77661344u, 77792418u, 77923492u, 78054566u,
    78185640u, 78316714u, 78447788u, 78578862u, 78709936u, 78841010u,
    78972084u, 79103158u, 79234232u, 79365306u, 79496380u, 79627454u,
    79824065u, 79955139u, 80086213u, 80217287u, 80348361u, 80479435u,
    80610509u, 80676032u, 80807120u, 80938194u, 81069268u, 81200342u,
    81331416u, 81462490u, 81593564u, 81724638u, 81855712u, 81986786u,
    82117860u, 82248934u, 82380008u, 82511082u, 82642156u, 82773230u,
    82904304u, 83035378u, 83166452u, 83297526u, 83428600u, 83559674u,
    83690748u, 83821822u, 83952896u, 84083970u, 84215044u, 84346118u,
    84477192u, 84608266u, 84739340u, 84870414u, 85001488u, 85132562u,
    90244401u, 90309938u, 90375475u, 90441012u, 90506549u, 90572086u,
    90637623u, 90703160u, 90768697u, 90834234u, 90899771u, 90965308u,
    91030845u, 91096382u, 91161919u, 91227456u, 91292993u, 91358530u,
    91424067u, 91489604u, 91555141u, 91620678u, 91686215u, 91751752u,
    91817289u, 91882826u, 91948363u, 92013900u, 92079437u, 92144974u,
    92210511u, 92276048u, 92341585u, 92407122u, 92472659u, 92538196u,
    92603733u, 92669270u, 494742627u, 503389696u, 503520770u, 503651844u,
    503782918u, 503913992u, 504045066u, 504176140u, 504307214u, 504438288u,
    504569362u, 504700436u, 504831510u, 504962584u, 505093658u, 505224732u,
    505355806u, 505486880u, 505617954u, 505749028u, 505880102u, 506011176u,
    506142250u, 506273324u, 506404398u, 506535472u, 506666546u, 506797620u,
    506928694u, 507059768u, 507190842u, 507321916u, 507452990u, 507584064u,
    507715138u, 507846212u, 507977286u, 508108360u, 508239434u, 508370508u,
    508501582u, 508632656u, 508763730u, 508894804u, 509025878u, 509156952u,
    509288026u, 509419100u, 509550174u, 509681248u, 509812322u, 509943396u,
    510074470u, 510205544u, 510336618u, 510467692u, 510598766u, 510729840u,
    510860914u, 510991988u, 511123062u, 511254136u, 511385210u, 511516284u,
    511647358u, 511778432u, 511909506u, 512040580u, 512171654u, 512302728u,
    512433802u, 512564876u, 512695950u, 512827024u, 512958098u, 513089172u,
    513482336u, 513875616u, 514006690u, 514137764u, 514268838u, 514399912u,
    514530986u, 514662060u, 514793134u, 514924208u, 515055282u, 515186356u,
    515317430u, 515448504u, 515579578u, 515710652u, 515841726u, 515972800u,
    516103874u, 516234948u, 516366022u, 516497096u, 516628170u, 516759244u,
    516890318u, 517021392u, 517152466u, 517283540u, 517414614u, 517545688u,
    517676762u, 517807836u, 517938910u, 518069984u, 518201058u, 518332132u,
    518463206u, 518594280u, 518725354u, 518856428u, 518987502u, 519118576u,
    519249650u, 519380724u, 519511798u, 519642872u, 520101640u, 520167177u,
    520232714u, 520298251u, 520363788u, 520429325u, 520494862u, 520560399u,
    521150232u, 521215769u, 521281306u, 521346843u, 521412380u, 521477917u,
    522198824u, 522264361u, 522329898u, 522395435u, 522460972u, 522526509u,
    522592046u, 522657583u, 523247416u, 523312953u, 523378490u, 523444027u,
    523509564u, 523575101u, 523640638u, 523706175u, 524296008u, 524361545u,
    524427082u, 524492619u, 524558156u, 524623693u, 525410137u, 525541211u,
    525672285u, 525803359u, 526393192u, 526458729u, 526524266u, 526589803u,
    526655340u, 526720877u, 526786414u, 526851951u, 527441850u, 527507387u,
    527572936u, 527638473u, 527704010u, 527769547u, 527835098u, 527900635u,
    527966200u, 528031737u, 528097258u, 528162795u, 528228346u, 528293883u,
    528490376u, 528555913u, 528621450u, 528686987u, 528752524u, 528818061u,
    528883598u, 528949135u, 529538968u, 529604505u, 529670042u, 529735579u,
    529801116u, 529866653u, 529932190u, 529997727u, 530587560u, 530653097u,
    530718634u, 530784171u, 530849708u, 530915245u, 530980782u, 531046319u,
    531636152u, 531701689u, 531832764u, 532546457u, 532881356u, 533733336u,
    533798873u, 534781928u, 534847465u, 535109612u, 536027132u, 558768434u,
    560996704u, 561062241u, 561127778u, 561193315u, 561258852u, 561324389u,
    561389926u, 561455463u, 561521000u, 561586537u, 561652074u, 561717611u,
    561783148u, 561848685u, 561914222u, 561979759u, 562307459u, 617620662u,
    617686199u, 617751736u, 617817273u, 617882810u, 617948347u, 618013884u,
    618079421u, 618144958u, 618210495u, 618276032u, 618341569u, 618407106u,
    618472643u, 618538180u, 618603717u, 618669254u, 618734791u, 618800328u,
    618865865u, 618931402u, 618996939u, 619062476u, 619128013u, 619193550u,
    619259087u, 741354496u, 741420033u, 741485570u, 741551107u, 741616644u,
    741682181u, 741747718u, 741813255u, 741878792u, 741944329u, 742009866u,
    742075403u, 742140940u, 742206477u, 742272014u, 742337551u, 742403088u,
    742468625u, 742534162u, 742599699u, 742665236u, 742730773u, 742796310u,
    742861847u, 742927384u, 742992921u, 743058458u, 743123995u, 743189532u,
    743255069u, 743320606u, 743386143u, 743451680u, 743517217u, 743582754u,
    743648291u, 743713828u, 743779365u, 743844902u, 743910439u, 743975976u,
    744041513u, 744107050u, 744172587u, 744238124u, 744303661u, 744369198u,
    744565856u, 744817210u, 744882750u, 745024615u, 745155689u, 745286763u,
    745942133u, 746663040u, 746794114u, 746925188u, 747056262u, 747187336u,
    747318410u, 747449484u, 747580558u, 747711632u, 747842706u, 747973780u,
    748104854u, 748235928u, 748367002u, 748498076u, 748629150u, 748760224u,
    748891298u, 749022372u, 749153446u, 749284520u, 749415594u, 749546668u,
    749677742u, 749808816u, 749939890u, 750070964u, 750202038u, 750333112u,
    750464186u, 750595260u, 750726334u, 750857408u, 750988482u, 751119556u,
    751250630u, 751381704u, 751512778u, 751643852u, 751774926u, 751906000u,
    752037074u, 752168148u, 752299222u, 752430296u, 752561370u, 752692444u,
    752823518u, 752954592u, 753085666u, 754978976u, 755044513u, 755110050u,
    755175587u, 755241124u, 755306661u, 755372198u, 755437735u, 755503272u,
    755568809u, 755634346u, 755699883u, 755765420u, 755830957u, 755896494u,
    755962031u, 756027568u, 756093105u, 756158642u, 756224179u, 756289716u,
    756355253u, 756420790u, 756486327u, 756551864u, 756617401u, 756682938u,
    756748475u, 756814012u, 756879549u, 756945086u, 757010623u, 757076160u,
    757141697u, 757207234u, 757272771u, 757338308u, 757403845u, 4282515233u,
    4282580770u, 4282646307u, 4282711844u, 4282777381u, 4282842918u, 4282908455u,
    4282973992u, 4283039529u, 4283105066u, 4283170603u, 4283236140u, 4283301677u,
    4283367214u, 4283432751u, 4283498288u, 4283563825u, 4283629362u, 4283694899u,
    4283760436u, 4283825973u, 4283891510u, 4283957047u, 4284022584u, 4284088121u,
    4284153658u
};

} }

#endif
