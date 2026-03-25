GoldenrodCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort
	goto GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship::
	call_if_unset FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship::
	call_if_unset FLAG_GOT_FRUSTRATION, GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	return

GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	return

GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort::
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end



GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "{JPN}いらっしゃいませ！\p"
	.string "{JPN}あらあなたのポケモン..$"
GoldenrodDeptStore_Text_5FReceptionistWait:
	.string "{JPN}ちょっと！そのわざマシンは\nもうわたしてるじゃない！$"
GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "{JPN}う-ん.\nわるくないけどよくもないわね\pトレーナーのあなたが\nもうすこしがんばらないと$"
GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "{JPN}とってもなついてるわね\n"
	.string "{JPN}あなたたちのコンビネーションなら\l"
	.string "{JPN}このわざつかいこなせそうね$"
GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "{JPN}なんだかめつきがわるいわね\n"
	.string "{JPN}そんなポケモンには\l"
	.string "{JPN}このわざマシンどうかしら？$"
GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
    .string "{JPN}きっとあなたのポケモンに\n"
	.string "{JPN}ぴったりのわざマシンがあるはずよ$"
GoldenrodDeptStore_Text_5FLass:
    .string "{JPN}にちようびにくるおねーさん\n"
	.string "{JPN}ポケモンのようすをみて\l"
	.string "{JPN}わざマシンをくれたりするのよ$"
GoldenrodDeptStore_Text_5FPokefanM:
    .string "{JPN}ひとからもらったポケモンは\n"
	.string "{JPN}なまえをかえることはできないよ\p"
	.string "{JPN}なまえをつけたひとの\n"
	.string "{JPN}きもちがこめられているからね$"
GoldenrodDeptStore_Text_Girl:
	.string "{JPN}おねえさんがおんがえしを\nくれたの！わたしのポケモン\nきっとわたしがすきなのね！$"
GoldenrodDeptStore_Text_5FDirectory:
	.string "{JPN}あなたごのみのポケモンに\p5かい わざマシンコーナー$"