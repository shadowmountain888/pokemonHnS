CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "{JPN}いらっしゃいませ!\n"
	.string "{JPN}タマムシデパートへ\l"
    .string "{JPN}ようこそ!\pあんないは かべに\nありますよ$"

CeladonDeptStore_Text_1FGentleman:
    .string "{JPN}このデパートは\n"
	.string "{JPN}コガネシティのデパートと\l"
    .string "{JPN}おなじチェーンてんなんだ\p"
	.string "{JPN}どちらも どうじきに\nかいそうしたんだよ$"

CeladonDeptStore_Text_1FTeacher:
    .string "{JPN}ここに きたのは\p"
	.string "{JPN}はじめてなの.\p"
	.string "{JPN}とても おおきくて...\pみちに まよいそう\nだわ.$"

CeladonDeptStore_Text_1FDirectory:
    .string "{JPN}1F サービスカウンター\p"
	.string "{JPN}2F トレーナーズマーケット\p"
    .string "{JPN}3F わざマシンショップ\p"
	.string "{JPN}4F ワイズマンギフト\p"
    .string "{JPN}5F ドラッグストア\p"
	.string "{JPN}6F おくじょうひろば$"
