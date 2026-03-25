extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{JPN}{STR_VAR_1}は おなかを\nつついてきた！");
static const u8 sHappyMsg01[] = _("{JPN}{STR_VAR_1}は うれしそうだけど\nはずかしがっている。");
static const u8 sHappyMsg02[] = _("{JPN}{STR_VAR_1}は たのしそうに\nついてくる！");
static const u8 sHappyMsg03[] = _("{JPN}{STR_VAR_1}は おちついている。");
static const u8 sHappyMsg04[] = _("{JPN}{STR_VAR_1}は いっしょに\nあるけて うれしそう！");
static const u8 sHappyMsg05[] = _("{JPN}{STR_VAR_1}は げんきいっぱいだ！");
static const u8 sHappyMsg06[] = _("{JPN}{STR_VAR_1}は とても\nうれしそうだ！");
static const u8 sHappyMsg07[] = _("{JPN}{STR_VAR_1}は はりきっている！");
static const u8 sHappyMsg08[] = _("{JPN}{STR_VAR_1}は まわりの においを\nかいでいる。");
static const u8 sHappyMsg09[] = _("{JPN}{STR_VAR_1}は うれしくて\nとびはねている！");
static const u8 sHappyMsg10[] = _("{JPN}{STR_VAR_1}は まだまだ\nげんきいっぱい！");
static const u8 sHappyMsg11[] = _("{JPN}ポケモンは けむりの においを\nかぎつけた！");
static const u8 sHappyMsg12[] = _("{JPN}{STR_VAR_1}は おなかを\nつついてくる！");
static const u8 sHappyMsg13[] = _("{JPN}ポケモンは からだを のばして\nリラックスしている。");
static const u8 sHappyMsg14[] = _("{JPN}{STR_VAR_1}は さきに いきたい\nみたいだ！");
static const u8 sHappyMsg15[] = _("{JPN}{STR_VAR_1}は いっしょうけんめい\nついてくる！");
static const u8 sHappyMsg16[] = _("{JPN}{STR_VAR_1}は うれしそうに\nすりよってきた！");
static const u8 sHappyMsg17[] = _("{JPN}{STR_VAR_1}は いきいき\nしている！");
static const u8 sHappyMsg18[] = _("{JPN}{STR_VAR_1}は とても\nうれしそうだ！");
static const u8 sHappyMsg19[] = _("{JPN}{STR_VAR_1}は うれしくて\nじっとしていられない！");
static const u8 sHappyMsg20[] = _("{JPN}{STR_VAR_1}は ゆっくり\nうなずいた。");
static const u8 sHappyMsg21[] = _("{JPN}{STR_VAR_1}は やるき\nまんまんだ！");
static const u8 sHappyMsg22[] = _("{JPN}{STR_VAR_1}は うろうろしながら\nいろんな おとを きいている。");
static const u8 sHappyMsg23[] = _("{JPN}{STR_VAR_1}は とても\nきょうみぶかそうだ。");
static const u8 sHappyMsg24[] = _("{JPN}{STR_VAR_1}は なんとか\nがんばっている。");
static const u8 sHappyMsg25[] = _("{JPN}{STR_VAR_1}は あかるい\nかおを みせた！");
static const u8 sHappyMsg26[] = _("{JPN}{STR_VAR_1}は うれしそうに\nわらっている！");
static const u8 sHappyMsg27[] = _("{JPN}ポケモンは はなの かおりを\nかいでいる。");
static const u8 sHappyMsg28[] = _("{JPN}{STR_VAR_1}は あなたに あえて\nとても うれしそう！");
static const u8 sHappyMsg29[] = _("{JPN}{STR_VAR_1}は こちらを むいて\nにっこりした！");
static const u8 sHappyMsg30[] = _("{JPN}{STR_VAR_1}は うれしそうに\nすりよってきた！");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("{JPN}ポケモンは いい てんきで\nうれしそうだ。");
static const u8 sHappyMsg32[] = _("{JPN}{STR_VAR_1}は とても おちついて\nじしんに みちている！");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{JPN}{STR_VAR_1}は じめんを\nつついている。");
static const u8 sNeutralMsg01[] = _("{JPN}{STR_VAR_1}は みはりを\nしている。");
static const u8 sNeutralMsg02[] = _("{JPN}{STR_VAR_1}は なにもない ところを\nじっと みている。");
static const u8 sNeutralMsg03[] = _("{JPN}{STR_VAR_1}は うろうろ\nしている。");
static const u8 sNeutralMsg04[] = _("{JPN}ポケモンは おおきな\nあくびを した！");
static const u8 sNeutralMsg05[] = _("{JPN}ポケモンは そわそわ\nまわりを みている。");
static const u8 sNeutralMsg06[] = _("{JPN}{STR_VAR_1}は こちらを みて\nわらっている。");
static const u8 sNeutralMsg07[] = _("{JPN}{STR_VAR_1}は そわそわと\nあたりを みまわしている。");
static const u8 sNeutralMsg08[] = _("{JPN}{STR_VAR_1}は おたけびを\nあげた！");
static const u8 sNeutralMsg09[] = _("{JPN}{STR_VAR_1}は すてきな ダンスを\nおどった！");
static const u8 sNeutralMsg10[] = _("{JPN}{STR_VAR_1}は やるきまんまんだ！");
static const u8 sNeutralMsg11[] = _("{JPN}{STR_VAR_1}は とおくを じっと\nみつめている。");
static const u8 sNeutralMsg12[] = _("{JPN}{STR_VAR_1}は みはっている！");
static const u8 sNeutralMsg13[] = _("{JPN}{STR_VAR_1}は とおくを みて\nほえた！");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{JPN}{STR_VAR_1}は めが\nまわっている。");
static const u8 sSadMsg01[] = _("{JPN}{STR_VAR_1}は あしを\nふんでくる！");
static const u8 sSadMsg02[] = _("{JPN}{STR_VAR_1}は すこし\nつかれたみたいだ。");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{JPN}{STR_VAR_1}は ごきげんが\nよくないようだ。");
static const u8 sSadMsg04[] = _("{JPN}{STR_VAR_1}は たおれそうだ！\n");
static const u8 sSadMsg05[] = _("{JPN}{STR_VAR_1}は いまにも\nたおれそう！");
static const u8 sSadMsg06[] = _("{JPN}{STR_VAR_1}は いっしょうけんめい\nついてこようとしている...");
static const u8 sSadMsg07[] = _("{JPN}{STR_VAR_1}は きんちょう\nしている。");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{JPN}{STR_VAR_1}は なんだか\nふまんそう...");
static const u8 sUpsetMsg01[] = _("{JPN}{STR_VAR_1}は ふまんそうな\nかおを している。");
static const u8 sUpsetMsg02[] = _("{JPN}...ポケモンは すこし\nさむそうだ。");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{JPN}{STR_VAR_1}は あめを さけて\nくさむらに かくれている。");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{JPN}{STR_VAR_1}は ほえた！");
static const u8 sAngryMsg01[] = _("{JPN}{STR_VAR_1}は おこったような\nかおを している！");
static const u8 sAngryMsg02[] = _("{JPN}{STR_VAR_1}は なぜか\nおこっているようだ。");
static const u8 sAngryMsg03[] = _("{JPN}ポケモンは むこうを むいて\nはんこうてきな かおを した。");
static const u8 sAngryMsg04[] = _("{JPN}{STR_VAR_1}は なきごえを\nあげた！");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{JPN}{STR_VAR_1}は じっと したを\nみている。");
static const u8 sPensiveMsg01[] = _("{JPN}{STR_VAR_1}は あたりを\nみまわしている。");
static const u8 sPensiveMsg02[] = _("{JPN}{STR_VAR_1}は したを\nのぞきこんでいる。");
static const u8 sPensiveMsg03[] = _("{JPN}{STR_VAR_1}は なんとか\nねむさと たたかっている...");
static const u8 sPensiveMsg04[] = _("{JPN}{STR_VAR_1}は うろうろ\nしているようだ。");
static const u8 sPensiveMsg05[] = _("{JPN}{STR_VAR_1}は ぼんやり\nまわりを みている。");
static const u8 sPensiveMsg06[] = _("{JPN}{STR_VAR_1}は おおきな あくびを\nした！");
static const u8 sPensiveMsg07[] = _("{JPN}{STR_VAR_1}は のんびり\nくつろいでいる。");
static const u8 sPensiveMsg08[] = _("{JPN}{STR_VAR_1}は あなたの かおを\nじっと みている。");
static const u8 sPensiveMsg09[] = _("{JPN}{STR_VAR_1}は あなたの かおを\nじーっと みている。");
static const u8 sPensiveMsg10[] = _("{JPN}{STR_VAR_1}は あなたに\nちゅうもくしている。");
static const u8 sPensiveMsg11[] = _("{JPN}{STR_VAR_1}は おくを じっと\nみつめている。");
static const u8 sPensiveMsg12[] = _("{JPN}{STR_VAR_1}は じめんの においを\nかいでいる。");
static const u8 sPensiveMsg13[] = _("{JPN}ポケモンは なにもないところを\nじっと みつめている。");
static const u8 sPensiveMsg14[] = _("{JPN}{STR_VAR_1}は するどい めで\nしゅうちゅうした！");
static const u8 sPensiveMsg15[] = _("{JPN}{STR_VAR_1}は しゅうちゅう\nしている。");
static const u8 sPensiveMsg16[] = _("{JPN}{STR_VAR_1}は こちらを むいて\nうなずいた。");
static const u8 sPensiveMsg17[] = _("{JPN}{STR_VAR_1}は すこし きんちょう\nしているようだ...");
static const u8 sPensiveMsg18[] = _("{JPN}{STR_VAR_1}は あなたの\nあしあとを みている。");
static const u8 sPensiveMsg19[] = _("{JPN}{STR_VAR_1}は あなたの めを\nまっすぐ みている。");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{JPN}{STR_VAR_1}は とつぜん\nちかづいてきた！");
static const u8 sLoveMsg01[] = _("{JPN}{STR_VAR_1}の ほっぺが\nあかくなっている！");
static const u8 sLoveMsg02[] = _("{JPN}わっ！ {STR_VAR_1}が とつぜん\nだきついてきた！");
static const u8 sLoveMsg03[] = _("{JPN}わっ！ {STR_VAR_1}が とつぜん\nあまえだした！");
static const u8 sLoveMsg04[] = _("{JPN}{STR_VAR_1}は あしに\nすりよってくる！");
static const u8 sLoveMsg05[] = _("{JPN}{STR_VAR_1}は てれている。");
static const u8 sLoveMsg06[] = _("{JPN}あっ！ {STR_VAR_1}が\nすりよってきた！");
static const u8 sLoveMsg07[] = _("{JPN}{STR_VAR_1}は あこがれの めで\nみつめている！");
static const u8 sLoveMsg08[] = _("{JPN}{STR_VAR_1}は ちかくに\nよってきた。");
static const u8 sLoveMsg09[] = _("{JPN}{STR_VAR_1}は あしもとに\nぴったり くっついている。");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{JPN}{STR_VAR_1}は たおれそうで\nあぶない！");
static const u8 sSurpriseMsg01[] = _("{JPN}{STR_VAR_1}は あなたに\nぶつかった！");
static const u8 sSurpriseMsg02[] = _("{JPN}{STR_VAR_1}は まだ じぶんの\nなまえに なれていないようだ。");
static const u8 sSurpriseMsg03[] = _("{JPN}{STR_VAR_1}は したを\nのぞきこんでいる。");
static const u8 sSurpriseMsg04[] = _("{JPN}ポケモンは つまずいて\nころびそうになった！");
static const u8 sSurpriseMsg05[] = _("{JPN}{STR_VAR_1}は なにかを かんじて\nほえている！");
static const u8 sSurpriseMsg06[] = _("{JPN}{STR_VAR_1}は さっぱりした\nようだ！");
static const u8 sSurpriseMsg07[] = _("{JPN}{STR_VAR_1}は とつぜん ふりむいて\nほえだした！");
static const u8 sSurpriseMsg08[] = _("{JPN}{STR_VAR_1}は とつぜん\nふりむいた！");
static const u8 sSurpriseMsg09[] = _("{JPN}ポケモンは とつぜん はなしかけ\nられて びっくりした！");
static const u8 sSurpriseMsg10[] = _("{JPN}くんくん なにか いい においが\nする！");
static const u8 sSurpriseMsg11[] = _("{JPN}{STR_VAR_1}は さっぱりした。");
static const u8 sSurpriseMsg12[] = _("{JPN}{STR_VAR_1}は ふらふらして\nたおれそうだ。");
static const u8 sSurpriseMsg13[] = _("{JPN}{STR_VAR_1}は たおれそうで\nあぶない。");
static const u8 sSurpriseMsg14[] = _("{JPN}{STR_VAR_1}は そろそろと\nあるいている。");
static const u8 sSurpriseMsg15[] = _("{JPN}{STR_VAR_1}は きんちょうで\nピリピリしている。");
static const u8 sSurpriseMsg16[] = _("{JPN}{STR_VAR_1}は ふしぎな けはいに\nびっくりした！");
static const u8 sSurpriseMsg17[] = _("{JPN}{STR_VAR_1}は こわくて\nすりよってきた！");
static const u8 sSurpriseMsg18[] = _("{JPN}{STR_VAR_1}は ふしぎな けはいを\nかんじている...");
static const u8 sSurpriseMsg19[] = _("{JPN}{STR_VAR_1}は きんちょうで\nピリピリしている。");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{JPN}{STR_VAR_1}は あめが ふってきて\nとても びっくりしている！");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("{JPN}ポケモンは なにかを さがして\nきょろきょろしている。");
static const u8 sCuriousMsg01[] = _("{JPN}ポケモンは まえを みていなくて\nぶつかってきた！");
static const u8 sCuriousMsg02[] = _("{JPN}くんくん！ ちかくに なにか\nあるのかな？");
static const u8 sCuriousMsg03[] = _("{JPN}{STR_VAR_1}は こいしを ころがして\nあそんでいる。");
static const u8 sCuriousMsg04[] = _("{JPN}{STR_VAR_1}は うろうろして\nなにかを さがしている。");
static const u8 sCuriousMsg05[] = _("{JPN}{STR_VAR_1}は あなたの においを\nかいでいる。");
static const u8 sCuriousMsg06[] = _("{JPN}{STR_VAR_1}は すこし\nためらっているようだ...");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{JPN}{STR_VAR_1}は すばやさを\nみせつけている！");
static const u8 sMusicMsg01[] = _("{JPN}{STR_VAR_1}は たのしそうに\nうごいている！");
static const u8 sMusicMsg02[] = _("{JPN}わっ！ {STR_VAR_1}が とつぜん\nおどりだした！");
static const u8 sMusicMsg03[] = _("{JPN}{STR_VAR_1}は しっかり\nついてくる！");
static const u8 sMusicMsg04[] = _("{JPN}{STR_VAR_1}は あなたと あそびたい\nみたいだ。");
static const u8 sMusicMsg05[] = _("{JPN}{STR_VAR_1}は たのしそうに\nスキップしている！");
static const u8 sMusicMsg06[] = _("{JPN}{STR_VAR_1}は はなうたを\nうたっている。");
static const u8 sMusicMsg07[] = _("{JPN}{STR_VAR_1}は あしもとに\nかみついてくる！");
static const u8 sMusicMsg08[] = _("{JPN}{STR_VAR_1}は ふりかえって\nこちらを みている。");
static const u8 sMusicMsg09[] = _("{JPN}{STR_VAR_1}は じまんの ちからを\nみせつけている！");
static const u8 sMusicMsg10[] = _("{JPN}わっ！ {STR_VAR_1}が とつぜん\nうれしそうに おどりだした！");
static const u8 sMusicMsg11[] = _("{JPN}{STR_VAR_1}は ごきげんだ！");
static const u8 sMusicMsg12[] = _("{JPN}{STR_VAR_1}は きままに\nとびはねている！");
static const u8 sMusicMsg13[] = _("{JPN}ポケモンは なつかしい においを\nかいでいるようだ...");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{JPN}{STR_VAR_1}は あめが ふって\nとても うれしそうだ。");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{JPN}{STR_VAR_1}は どくの えいきょうで\nふるえている。");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
