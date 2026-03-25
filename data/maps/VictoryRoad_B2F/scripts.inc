VictoryRoad_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_B2F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_B2F_OnTransition
	.byte 0

VictoryRoad_B2F_OnResume:
	callnative SetTimeBasedEncounters
	end

VictoryRoad_B2F_OnTransition:
	callnative SetTimeBasedEncounters
	goto_if_set FLAG_UNLOCK_BIRDS, VictoryRoad_B2F_SwitchToModern
	end

VictoryRoad_B2F_SwitchToModern::
	setmaplayoutindex LAYOUT_VICTORY_ROAD_B2F_MODERN
	end

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_NORMAN, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_KENJI, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "{JPN}かぞくぜんいんで いっしょに\n"
	.string "{JPN}しゅぎょうしたんだ!\l"
	.string "{JPN}だれにも まけないぞ!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "{JPN}かぞくより つよいって?!\n"
	.string "{JPN}そんなことが あるのか?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "{JPN}かぞくの なかでは いちばん\n"
	.string "{JPN}つよかったのに... いままで\p"
	.string "{JPN}まけたことなんて なかったのに...\n"
	.string "{JPN}じしんを なくしちゃったよ...\pいえに かえろうかな...$"
VictoryRoad_B2F_Text_OwenIntro:
	.string "{JPN}きょうてきな ちびっこが いるって\n"
	.string "{JPN}うわさを きいたが きみのことか?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "{JPN}ちいさいのに つよいな!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "{JPN}うわさで きいたんだが その\n"
	.string "{JPN}つよいちびっこは トウカシティの\lしゅっしんらしいな$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "{JPN}すこし つかれてきたでしょう?$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "{JPN}つかれた ようすが ないわね!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "{JPN}チャンピオンロードと ポケモンリーグは\n"
	.string "{JPN}ながくて たいへんな ちょうせんよ\l"
	.string "{JPN}つかれに きをつけて!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "{JPN}ジムバッジを たくさん もってるからって\n"
	.string "{JPN}ゆだんしちゃ だめよ\p"
	.string "{JPN}あなたより つよいひとは\n"
	.string "{JPN}かならず いるんだから!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "{JPN}あなたの ほうが つよいのね!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "{JPN}あつめた バッジを みつめて\n"
	.string "{JPN}たたかった トレーナーたちを\lおもいだしなさい$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "{JPN}ここまで きたけど きんちょうで\n"
	.string "{JPN}おなかが いたくて いたくて...$"
VictoryRoad_B2F_Text_FelixDefeat:
	.string "{JPN}うう...\n"
	.string "{JPN}いたいよ...$"
VictoryRoad_B2F_Text_FelixPostBattle:
	.string "{JPN}ポケモンリーグが ちかづいてると\n"
	.string "{JPN}おもうと きんちょうして しまう\p"
	.string "{JPN}へいきな ふりを するのが\nせいいっぱいだよ$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "{JPN}えりーとちゅうの えりーとが\n"
	.string "{JPN}このどうくつに あつまるのよ\p"
	.string "{JPN}どう? ちょうしは?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "{JPN}ぜんぜん どうじて いないのね!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "{JPN}きもが すわってるわね! きにいったわ!\n"
	.string "{JPN}その ちょうしで がんばって!$"

