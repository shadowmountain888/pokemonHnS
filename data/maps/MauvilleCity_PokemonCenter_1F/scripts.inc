.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "{JPN}あそこにいるおとこのひと \n"
	.string "{JPN}へんなことばっかりいうのよ!\p"
	.string "{JPN}へんなかんじでおもしろいの.\n"
	.string "{JPN}わすれられないわ!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "{JPN}レコードコーナーにアクセス\n"
	.string "{JPN}したら カナズミでなにが\l"
	.string "{JPN}はやってるかのデータが\l"
	.string "{JPN}こうしんされたよ.\p"
	.string "{JPN}これでそのデータが\nともだちとおなじになった!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "{JPN}ポケモンセンターの2かいに\n"
	.string "{JPN}レコードコーナーができたのね.\p"
	.string "{JPN}なんのことかわからないけど \n"
	.string "{JPN}たのしそう.いってみる!$"

