.set LOCALID_CELADON_FALKNER, 5

CeladonCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept5_EventScript_Gent::
	msgbox CeladonDeptStore5F_Text_Gentleman, MSGBOX_NPC
	end
CeladonDept5_EventScript_Sailor::
	msgbox CeladonDeptStore5F_Text_Sailor, MSGBOX_NPC
	end
CeladonDept5_EventScript_Teacher::
	msgbox CeladonDeptStore5F_Text_Teacher, MSGBOX_NPC
	end
CeladonDept5_EventScript_Directory::
	msgbox CeladonDeptStore5F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore5_EventScript_Falkner::
	lock
	faceplayer
	msgbox CeladonDeptStore5_Text_Falkner, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CELADON_FALKNER
	removeobject LOCALID_CELADON_FALKNER
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_FALKNER
	release
	end

CeladonDeptStore5_Text_Falkner:
	.string "{JPN}{PLAYER}.ここで きみに\n"
	.string "{JPN}あうとは おもわなかったよ.\p"
	.string "{JPN}ぼくの とりポケモンの\n"
	.string "{JPN}どうぐを かいに きたんだ.\p"
	.string "{JPN}もう いちど しょうぶしたけりゃ\n"
	.string "{JPN}ヤマブキシティの どうじょうに\nいるから きてくれ.$"

CeladonDeptStore5F_Text_Gentleman:
	.string "{JPN}ポケモンの のうりょくを\n"
	.string "{JPN}あげる どうぐが ほしいんだが\l"
	.string "{JPN}おかねが たりないんだ...$"
CeladonDeptStore5F_Text_Sailor:
	.string "{JPN}ポイントアップが ほしいんだ!\n"
	.string "{JPN}わざの PPを ふやせるからな\lでも うってないんだよな...$"
CeladonDeptStore5F_Text_Teacher:
	.string "{JPN}どうぐを つかうと ポケモンは\n"
	.string "{JPN}よろこぶのよ\p"
	.string "{JPN}でも きらいな どうぐも\nあるから きをつけてね...$"
CeladonDeptStore5F_Text_Directory:
	.string "{JPN}5F: くすりや$"
