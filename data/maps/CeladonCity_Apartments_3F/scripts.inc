CeladonCity_Apartments_3F_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "{JPN}そうなの?\p"
	.string "{JPN}わたしが ゲームデザイナー\n"
	.string "{JPN}よ!\p"
	.string "{JPN}ポケモンずかんを かんせい\nさせるのは たいへんだけど\lがんばって!$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "{JPN}わあ! すばらしいわ!\n"
	.string "{JPN}ポケモンずかんが かんせい\l"
	.string "{JPN}してるじゃない!\pおめでとう!$"

GameFreak_Text_GraphicArtist:
	.string "{JPN}ぼくは グラフィックアーティ\n"
	.string "{JPN}スト だよ.\pきみを かいたんだ!$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "{JPN}ぼくは グラフィックアーティ\n"
	.string "{JPN}スト だよ.\p"
	.string "{JPN}あ ポケモンずかんが\n"
	.string "{JPN}かんせいしたんだね?\pそつぎょうしょうじょうを\nいんさつしようか?$"

GameFreak_Text_GraphicArtistRefused:
	.string "{JPN}そつぎょうしょうじょうが\n"
	.string "{JPN}ほしくなったら こえを\lかけてよ.$"

GameFreak_Text_GraphicArtistError:
	.string "{JPN}なにか おかしいな.\n"
	.string "{JPN}いんさつを ちゅうしするよ.$"

GameFreak_Text_Programmer:
	.string "{JPN}ぼく? ぼくは プログラマー\n"
	.string "{JPN}だよ.\pスロットマシンで\nあそんでよ!$"

GameFreak_Text_CharacterDesigner:
	.string "{JPN}ふたごちゃんって かわいい\n"
	.string "{JPN}でしょ?\p"
	.string "{JPN}ミカンも きれいだし.\pああ だいすき!$"

CeladonMansion3F_Text_DevRoomSign:
	.string "{JPN}ゲームフリーク かいはつしつ$"

CeladonMansion3F_Text_Drawing:
	.string "{JPN}かわいい おんなのこの\n"
	.string "{JPN}こまかい えが かいてある.$"

CeladonMansion3F_Text_GameProgram:
	.string "{JPN}ゲームの プログラムだ.\n"
	.string "{JPN}いじったら ゲームに バグが\l"
	.string "{JPN}はいっちゃうかも!$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "{JPN}しりょうが ぎっしり つまって\n"
	.string "{JPN}いる.ポケにんぎょうまで\l"
	.string "{JPN}あるよ.$"
