Route38_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
	.string "{JPN}そらたかく とべ!\n"
	.string "{JPN}あいするとりポケモンよ!$"

Route38_Text_BirdKeeperTobyBeaten:
	.string "{JPN}いまは とんでにげたい\n"
	.string "{JPN}きぶんだよ$"

Route38_Text_BirdKeeperTobyAfter:
	.string "{JPN}タンバシティで しゅぎょうして\n"
	.string "{JPN}ポケモンに そらをとぶを\lおしえるつもりだ$"

Route38_Text_SchoolboyChad1Seen:
	.string "{JPN}きょう ならったことを\n"
	.string "{JPN}ためしてみるよ$"

Route38_Text_SchoolboyChad1Beaten:
	.string "{JPN}べんきょうが たりなかった\n"
	.string "{JPN}みたいだね$"

Route38_Text_SchoolboyChadAfter:
	.string "{JPN}たくさん テストが あるから\n"
	.string "{JPN}ポケモンの じかんが\l"
	.string "{JPN}あんまり ないんだ\p"
	.string "{JPN}だから あそべるときは\n"
	.string "{JPN}ほんとうに しゅうちゅう\lするんだよ$"

Route38_Text_LassDana1Seen:
	.string "{JPN}あなた ポケモンが\n"
	.string "{JPN}じょうずそうね\p"
	.string "{JPN}もし そうなら わたしに\n"
	.string "{JPN}アドバイス してくれない?$"

Route38_Text_LassDana1Beaten:
	.string "{JPN}なるほど そんなふうに\n"
	.string "{JPN}たたかうのね$"

Route38_Text_LassDanaAfter:
	.string "{JPN}いいこと しってるの!\p"
	.string "{JPN}モーモーぼくじょうの ミルクは\n"
	.string "{JPN}あじで ゆうめいなのよ$"

Route38_Text_BeautyValerieSeen:
	.string "{JPN}こんにちは! かわいい\n"
	.string "{JPN}トレーナーね!\p"
	.string "{JPN}あなたの ポケモン\nみせて もらえる?$"

Route38_Text_BeautyValerieBeaten:
	.string "{JPN}あなたの ポケモンが\n"
	.string "{JPN}みれて よかったわ!$"

Route38_Text_BeautyValerieAfter:
	.string "{JPN}ポケモンを みていると\n"
	.string "{JPN}しんけいが やすまるみたい$"

Route38_Text_SailorHarrySeen:
	.string "{JPN}かいがいに いったから\n"
	.string "{JPN}いろんな ポケモンの ことを\l"
	.string "{JPN}しってるぞ!$"

Route38_Text_SailorHarryBeaten:
	.string "{JPN}きみの うでまえは\nせかいきゅうだ!$"

Route38_Text_SailorHarryAfter:
	.string "{JPN}せかいじゅうの いろんなひとが\n"
	.string "{JPN}ポケモンと しあわせに\l"
	.string "{JPN}くらしているよ$"

Route38_Text_BeautyOliviaSeen:
	.string "{JPN}わたしと わたしのポケモン\n"
	.string "{JPN}うつくしいと おもわない?$"

Route38_Text_BeautyOliviaBeaten:
	.string "{JPN}わたしたち まいにち\n"
	.string "{JPN}モーモーミルクを のんでるの$"

Route38_Text_BeautyOliviaAfter:
	.string "{JPN}モーモーミルクは びようと\n"
	.string "{JPN}けんこうに いいんだけど\p"
	.string "{JPN}ふべんなことに いちどに\n"
	.string "{JPN}ひとつしか うってくれないの$"

Route38_Text_Sign:
	.string "{JPN}38ばんどうろ\p"
	.string "{JPN}アサギシティ - エンジュシティ$"

Route38_Text_TrainerTips:
	.string "{JPN}おとくなけいじばん！\p"
	.string "{JPN}ポケモンがしんかしそうなとき\n"
	.string "{JPN}Bボタンをおすと\l"
	.string "{JPN}びっくりしてしんかをやめます\l"
	.string "{JPN}これをしんかキャンセルといいます$"

Route38_Text_WaterSign:
	.string "{JPN}すいえいと つりは きんし\n"
	.string "{JPN}のうぎょうよう みずのみ\p"
	.string "{JPN}-エンジュ ぎかい$"
