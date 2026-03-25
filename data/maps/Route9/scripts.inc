Route9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route9_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route9_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route9_EventScript_Dean::
	trainerbattle_single TRAINER_DEAN Route9_Text_CamperDeanSeen, Route9_Text_CamperDeanBeaten
	msgbox Route9_Text_CamperDeanAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Heidi::
	trainerbattle_single TRAINER_HEIDI Route9_Text_PicnickerHeidiSeen, Route9_Text_PicnickerHeidiBeaten
	msgbox Route9_Text_PicnickerHeidiAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Edna::
	trainerbattle_single TRAINER_EDNA Route9_Text_PicnickerEdnaSeen, Route9_Text_PicnickerEdnaBeaten
	msgbox Route9_Text_PicnickerEdnaAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sid::
	trainerbattle_single TRAINER_SID Route9_Text_CamperSidSeen, Route9_Text_CamperSidBeaten
	msgbox Route9_Text_CamperSidAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Tim::
	trainerbattle_single TRAINER_TIM Route9_Text_HikerTimSeen, Route9_Text_HikerTimBeaten
	msgbox Route9_Text_HikerTimAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sidney::
	trainerbattle_single TRAINER_SIDNEY Route9_Text_HikerSidneySeen, Route9_Text_HikerSidneyBeaten
	msgbox Route9_Text_HikerSidneyAfter, MSGBOX_AUTOCLOSE
	end

Route9_EventScript_Sign::
	msgbox Route9_Text_Sign, MSGBOX_SIGN
	end

Route9_Text_CamperDeanSeen:
	.string "{JPN}いわやまトンネルを\nたんけんしにきたんだ$"

Route9_Text_CamperDeanBeaten:
	.string "{JPN}うわあ! きけんだな$"

Route9_Text_CamperDeanAfter:
	.string "{JPN}いわやまトンネルに\n"
	.string "{JPN}はいるまえに ぼくの\l"
	.string "{JPN}ポケモンが きずついちゃった\p"
	.string "{JPN}すぐにポケモンセンターに\nつれていかなくちゃ!$"

Route9_Text_PicnickerHeidiSeen:
	.string "{JPN}ピクニックに いったこと\n"
	.string "{JPN}ある?\pとっても たのしいのよ!$"

Route9_Text_PicnickerHeidiBeaten:
	.string "{JPN}あああー!$"

Route9_Text_PicnickerHeidiAfter:
	.string "{JPN}おいしいものを たくさん\n"
	.string "{JPN}やいて みんなで わけあうの\p"
	.string "{JPN}すっごく おいしいのよ!$"

Route9_Text_CamperSidSeen:
	.string "{JPN}きみ! ごみを すてるなよ!$"

Route9_Text_CamperSidBeaten:
	.string "{JPN}たんに いってただけ\nなのに...$"
Route9_Text_CamperSidAfter:
	.string "{JPN}ごめん きみは ごみを\n"
	.string "{JPN}すててなかったね\lぼくの みまちがいだった$"

Route9_Text_PicnickerEdnaSeen:
	.string "{JPN}ひとは ごみを のこして\n"
	.string "{JPN}いっちゃ だめよね$"

Route9_Text_PicnickerEdnaBeaten:
	.string "{JPN}あーあ... まけちゃった...$"
Route9_Text_PicnickerEdnaAfter:
	.string "{JPN}エネルギーを せつやくするのも\n"
	.string "{JPN}たいせつだけど しぜんかんきょうの\l"
	.string "{JPN}ほうが もっと だいじなのよ$"

Route9_Text_HikerTimSeen:
	.string "{JPN}しろがねやまを こえて\n"
	.string "{JPN}やってくる...\p"
	.string "{JPN}しろがねやまって ジョウトに\nあるんだよね?$"

Route9_Text_HikerTimBeaten:
	.string "{JPN}うたに むちゅうに\nなっちゃってたよ...$"
Route9_Text_HikerTimAfter:
	.string "{JPN}バトルは しゅうちゅうりょく\nだからな$"

Route9_Text_HikerSidneySeen:
	.string "{JPN}ひみつを おしえてやろう\p"
	.string "{JPN}でも そのまえに バトルだ!$"

Route9_Text_HikerSidneyBeaten:
	.string "{JPN}あーあ! まけちまった...$"
Route9_Text_HikerSidneyAfter:
	.string "{JPN}はつでんしょは ちいさな\n"
	.string "{JPN}かわの むこうがわに あるんだ$"

Route9_Text_Sign:
	.string "{JPN}ここは9ばんどうろ\n"
	.string "{JPN}ひがしイワヤマトンネル$"