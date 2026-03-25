.set LOCALID_MUSEUM_ROOTFOSSIL, 5
.set LOCALID_MUSEUM_CLAWFOSSIL, 6

PewterCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "{JPN}いらっしゃいませ\p"
	.string "{JPN}げんざいおおきなひょうほんは\n"
	.string "{JPN}よそのはくぶつかんへ\l"
	.string "{JPN}かしだしちゅうなんです\p"
	.string "{JPN}ですからいまだけとくべつに\n"
	.string "{JPN}にゅうじょうむりょう！\p"
	.string "{JPN}どうぞ\n"
	.string "{JPN}ごじゆうにおはいりください$"
PewterCity_Museum_1F_Text_FossilWoman:
	.string "{JPN}あなたは つよい トレーナー\n"
	.string "{JPN}ですね.\p"
	.string "{JPN}カウンターの うえにある\n"
	.string "{JPN}かせきは あまり やくに\n"
	.string "{JPN}たたないんです.\p"
	.string "{JPN}ぎんいろの かみのけの\nへんな おとこが たくさん\nもってきたんですよ.\pよろしければ もって\nいってください.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "{JPN}わたしたちは アルフのいせきの\n"
	.string "{JPN}けんきゅうしゃたちと よく\n"
	.string "{JPN}じょうほうを こうかんしています.\p"
	.string "{JPN}パソコンを つかって かせきも\nこうかんしているんですよ!$"

PewterCity_Museum_1F_Text_Oldman:
	.string "{JPN}ありがたや！ありがたや！\p"
	.string "{JPN}りゅうじんさまの\n"
	.string "{JPN}ほねをおがめるとは！$"
PewterCity_Museum_1F_Text_Bones:
	.string "{JPN}むかしの ドラゴンポケモンの\n"
	.string "{JPN}ほねです.$"
