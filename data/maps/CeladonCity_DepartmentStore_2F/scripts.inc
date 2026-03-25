CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "{JPN}さいきん トレーナーに なったんだ.\p"
	.string "{JPN}むすこに すすめられてね.\p"
	.string "{JPN}べんりな どうぐの しなぞろえに\n"
	.string "{JPN}かんしんしているよ.$"

CeladonDeptStore2F_Text_Youngster:
	.string "{JPN}おとうさんが どうぐの なまえや\n"
	.string "{JPN}つかいかたを おぼえるのに\l"
	.string "{JPN}くろうしてるんだ...$"
CeladonDeptStore2F_Text_Directory:
	.string "{JPN}トレーナーこうきゅうひん!\p"
	.string "{JPN}2F: トレーナーズマーケット$"

