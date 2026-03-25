PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "{JPN}センリが わたしたちの\n"
	.string "{JPN}まちの あたらしい ジムリーダーに\l"
	.string "{JPN}なったんだ.\p"
	.string "{JPN}とおいところから かぞくを\nよんだって きいたよ.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "{JPN}いちど センリと たたかったけど\n"
	.string "{JPN}ふう  つよすぎるよ.\p"
	.string "{JPN}なんて いったら いいのかな?\p"
	.string "{JPN}かれは ポケモンのために\n"
	.string "{JPN}いきてるって かんじだった.$"

