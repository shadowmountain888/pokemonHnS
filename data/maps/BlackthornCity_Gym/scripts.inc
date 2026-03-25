BlackthornCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
	.string "{JPN}イブキ: わたしがイブキ!\nせかいでいちばんの\lドラゴンつかいよ\p"
	.string "{JPN}じつりょくもポケモンリーグ\nしてんのうにだって\l"
	.string "{JPN}まけてなんかないわよ!\lどうそれでもたたかうの?\p"
	.string "{JPN}...そうわかったわ\nじゃはじめましょう!\p"
	.string "{JPN}わたしもトレーナー\nどんなあいてだって\l"
	.string "{JPN}ぜんりょくでぶつかってあげる!\p$"
BlackthornGym_Text_ClairWinText:
	.string "{JPN}イブキ: わたしはみとめないわ\p"
	.string "{JPN}まけていうのもなんだけど\nあなたのかんがえかたでは\l"
	.string "{JPN}ポケモンリーグにちょうせんなんて\lムリにきまってるわよ\p"
	.string "{JPN}...そうだわ!\p"
	.string "{JPN}このポケモンジムのうらに\nりゅうのあなとよばれる\lばしょがあるの\p"
	.string "{JPN}ちゅうおうにほこらがあるから\nそこへいってごらんなさい\p"
	.string "{JPN}もしそこであなたの\nかんがえをみとめられたなら\p"
	.string "{JPN}わたしもあなたが\nジムバッジをわたすにふさわしい\l"
	.string "{JPN}トレーナーだとみとめてあげるわ!$"
BlackthornGym_Text_ClairText_GoToDragonsDen:
	.string "{JPN}わたしはみとめないわ\pまけていうのもなんだけど\nポケモンリーグはまだムリよ\pそうだわ！ドラゴンつかいの\nしれんをうけなさい\pこのジムのうらにりゅうのあなと\nよばれるばしょがあるの\pちゅうおうにちいさなほこらが\nあるからそこへいきなさい\pあなたのあまいかんがえを\nすてることができたなら\lジムバッジにふさわしい\lトレーナーとみとめてあげる！$"
BlackthornGym_Text_ClairText_TooMuchToExpect:
	.string "{JPN}イブキ: どうしたの?\p"
	.string "{JPN}やっぱりあなたじゃムリかしら?$"
BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "{JPN}おそいわよ！\n"
	.string "{JPN}さっさとうけとりなさい！$"
BlackthornGym_Text_ClairText_DescribeTM:
	.string "{JPN}それはドラゴンクローよ\pどんなわざかはじぶんでしらべなさい$"
BlackthornGym_Text_ClairText_League:
	.string "{JPN}どうしたのよ？\pポケモンリーグに\nいかないの？\pばしょがわからないの？\pここからワカバタウンにいって\nひがしになみのりしなさい\nそのさきはとてもきびしいわよ\pポケモンリーグで\nまけたりしないでよ！\pまけたらわたしがもっと\nくやしくなっちゃうじゃない！\pぜんりょくでがんばりなさい$"
BlackthornGym_Text_ClairAfterLeague:
	.string "{JPN}やったのね？\pあなたはもうジョウトチャンプよ$"
BlackthornGym_Text_ClairRematchText:
	.string "{JPN}やったわね..\pあなたはジョウトのチャンピオン\pつよさはみとめるけど\nもういちどわたしとたたかえる？\pドラゴンつかいとして\nこんどはようしゃしないわよ\pさいせんしましょうか？$"
BlackthornGym_Text_ClairRematchDefeatText:
	.string "{JPN}まけた？\pまた？\pしんじられない..\nなにかのまちがいよ..$"
BlackthornGym_Text_CooltrainermCodySeenText:
	.string "{JPN}やっとドラゴンタイプの\nポケモンがつかえるようになった！$"
BlackthornGym_Text_CooltrainermCodyBeatenText:
	.string "{JPN}ちくしょう！カイリューがいれば！$"
BlackthornGym_Text_CooltrainermCodyAfterBattleText:
	.string "{JPN}ドラゴンつかいのいちぞくは\nしすうのきょかがないと\lドラゴンポケモンはつかえないんだ$"
BlackthornGym_Text_CooltrainerfFranSeenText:
	.string "{JPN}なまえもしらないトレーナーを\nとおすわけにはいかないわ！\pイブキさんがおこっちゃう！$"
BlackthornGym_Text_CooltrainerfFranBeatenText:
	.string "{JPN}あーん..まけちゃった..$"
BlackthornGym_Text_CooltrainerfFranAfterBattleText:
	.string "{JPN}やばい..イブキさんにおこられる..$"
BlackthornGym_Text_CooltrainermPaulSeenText:
	.string "{JPN}ドラゴンとのはつせんか？\pどれだけつよいかみせてやる！$"
BlackthornGym_Text_CooltrainermPaulBeatenText:
	.string "{JPN}ドラゴンポケモンがまけた？$"
BlackthornGym_Text_CooltrainermPaulAfterBattleText:
	.string "{JPN}ワタルがきみにまたあいたいって？\nそんなばかな！$"
BlackthornGym_Text_CooltrainermMikeSeenText:
	.string "{JPN}おれがまけるかくりつ？\nいちパーセントもないぜ！$"
BlackthornGym_Text_CooltrainermMikeBeatenText:
	.string "{JPN}おかしいな$"
BlackthornGym_Text_CooltrainermMikeAfterBattleText:
	.string "{JPN}じぶんのよわさがわかったよ\pおしえてくれてありがとう！$"
BlackthornGym_Text_CooltrainerfLolaSeenText:
	.string "{JPN}ドラゴンはせいなるポケモンよ\pせいめいりょくにあふれてる\pほんきじゃないと\nかつことはできないわ$"
BlackthornGym_Text_CooltrainerfLolaBeatenText:
	.string "{JPN}やるじゃない！$"
BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
	.string "{JPN}ドラゴンタイプのわざには\nドラゴンはよわいのよ$"
BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
	.string "{JPN}おーす!\nみらいのチャンピオン!\p"
	.string "{JPN}このジムはあしばがふあんていで\nキケンだから\l"
	.string "{JPN}ポケモンはしまっておいてくれよな\p"
	.string "{JPN}...さて\nイブキがつかうポケモンは\lでんせつのいきもの\l"
	.string "{JPN}せいなるドラゴンポケモン!\p"
	.string "{JPN}ちょっとやそっとじゃ\nダメージをあたえられない!\p"
	.string "{JPN}...だがな\nこおりタイプのわざには\lよわいってはなしだぜ!$"
BlackthornGym_Text_GuideWinText:
	.string "{JPN}おいおいイブキにかつなんて\nこりゃたいしたもんだぜ!\p"
	.string "{JPN}イブキはああいってるけど\nきみはじゅうぶんつよい!\l"
	.string "{JPN}...とおれはおもうぜ\p"
	.string "{JPN}まここはイブキの\nいうとおりにしておいたほうが\lよさそうだけどな!$"
BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "{JPN}フスベシティポケモンジム$"
BlackthornGym_Text_GymStatueCertified:
	.string "{JPN}フスベシティポケモンジム\p"
	.string "{JPN}ジムリーダーイブキ\nにんていトレーナー!\l{PLAYER}$"
