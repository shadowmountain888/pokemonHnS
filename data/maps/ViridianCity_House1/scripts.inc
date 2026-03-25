ViridianCity_House1_MapScripts::
	.byte 0

ViridianCity_House1_EventScript_Pokefan::
	msgbox ViridianCity_House1_Text_PokefanM, MSGBOX_NPC
	end

ViridianCity_House1_EventScript_Lass::
	msgbox ViridianCity_House1_Text_Lass, MSGBOX_NPC
	end


ViridianCity_House1_EventScript_Speary::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Speary, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_EventScript_Rattey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox ViridianCity_House1_Text_Rattey, MSGBOX_DEFAULT
	waitmoncry
	release
	end

ViridianCity_House1_Text_PokefanM:
	.string "{JPN}ポケモンのニックネーム\n"
	.string "{JPN}ちゃんとかんがえてつけてる？\p"
	.string "{JPN}いいニックネームをつけておくと\n"
	.string "{JPN}ひととこうかんしたとき\l"
	.string "{JPN}たのしさがプラスされるよね！$"
ViridianCity_House1_Text_Lass:
	.string "{JPN}オニスズメのオニチャンと\n"
	.string "{JPN}コラッタのコーチャンよ！$"
ViridianCity_House1_Text_Speary:
	.string "{JPN}ちゅちゅん！$"
ViridianCity_House1_Text_Rattey:
	.string "{JPN}きっきーっ！$"
