CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "{JPN}かのじょに おくる なみのりメールを\n"
	.string "{JPN}かいに きたんだ.\p"
	.string "{JPN}え? ざいこが ないって?$"

CeladonDeptStore4F_Text_Youngster:
	.string "{JPN}ここは ラブリーメールが かえる\n"
	.string "{JPN}ゆいいつの ばしょなんだ.\p"
	.string "{JPN}すくなくとも そうだったけど.\n"
	.string "{JPN}ざいこぎれって いわれちゃった.$"

CeladonDeptStore4F_Text_Directory:
	.string "{JPN}きもちを つたえる ギフト!\p"
	.string "{JPN}4F: ワイズマン ギフト$"
