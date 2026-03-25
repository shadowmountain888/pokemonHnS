Gate_IlexForest_Route34_MapScripts::
	.byte 0

Route34IlexForestGate_EventScript_Lass::
	lock
	faceplayer
	msgbox Route34IlexForestGate_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34IlexForestGate_EventScript_Butterfree::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BUTTERFREE, CRY_MODE_NORMAL
	msgbox Route34IlexForestGate_Text_Butterfree, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34IlexForestGate_Text_Lass:
	.string "{JPN}まもりがみを まつった ほこらを\n"
	.string "{JPN}みた?\p"
	.string "{JPN}もりを じだいを こえて\n"
	.string "{JPN}みまもって いるのよ.\p"
	.string "{JPN}それは くさタイプの\n"
	.string "{JPN}ポケモンだと おもうの.$"

Route34IlexForestGate_Text_Butterfree:
	.string "{JPN}バタフリー: フリー!$"
