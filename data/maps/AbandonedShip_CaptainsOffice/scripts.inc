AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_GARBAGEFLAG, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "{JPN}わたしは クスノキせんちょうの\n"
	.string "{JPN}たのみで このふねを しらべているの.\p"
	.string "{JPN}スキャナーを さがすことも\n"
	.string "{JPN}たのまれたんだけど まだ\nみつかってないのよ...$"
AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "{JPN}おお!それは スキャナーですね!\p"
	.string "{JPN}すみませんが それを\n"
	.string "{JPN}ダイゴさんに とどけて\l"
	.string "{JPN}もらえませんか?\p"
	.string "{JPN}わたしは この ふねを\nもう すこし しらべたいのです$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "{JPN}この ふねの なまえは\n"
	.string "{JPN}S.S.カクタスです\lむかしの じだいの もののようですね$"

