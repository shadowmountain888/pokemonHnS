Route5_House_MapScripts::
	.byte 0

Route5_House_EventScript_Granny::
	goto_if_set FLAG_GOT_CLEANSE_TAG, Route5_House_EventScript_GrannyAfter
	msgbox Route5_House_Text_Granny1, MSGBOX_NPC
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_CLEANSE_TAG
	release
	end

Route5_House_EventScript_GrannyAfter::
	msgbox Route5_House_Text_Granny2, MSGBOX_NPC
	end

Route5_House_EventScript_Woman::
	msgbox Route5_House_Text_Woman, MSGBOX_NPC
	end

Route5_House_Text_Granny1:
	.string "{JPN}きえーーーいっ！\p"
	.string "{JPN}おぬしにふきつなカゲが\n"
	.string "{JPN}とりついておるうっ！\l"
	.string "{JPN}これをもっていくがよい！$"
Route5_House_Text_Granny2:
	.string "{JPN}あぶないところじゃった！\n"
	.string "{JPN}これであんしんじゃ！$"
Route5_House_Text_Woman:
	.string "{JPN}うちのおばあちゃん\n"
	.string "{JPN}おはらいにこってるのよ\l"
	.string "{JPN}ごめんねおどろかせちゃって$"
