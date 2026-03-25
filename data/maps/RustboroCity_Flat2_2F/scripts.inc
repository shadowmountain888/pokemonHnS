RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "{JPN}むかしは デボンも ちっちゃな\n"
	.string "{JPN}かいしゃだったんだよ$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "{JPN}おとうさんが かいしゃで\n"
	.string "{JPN}おしごとしてるの\p"
	.string "{JPN}おとうさんが つくったの!\nでも わたしには つかえないから\nあげる$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "{JPN}おとうさんが かいしゃで\n"
	.string "{JPN}おしごとしてるの\p"
	.string "{JPN}わたしも おおきくなったら\nデボンで おしごとするんだ$"

