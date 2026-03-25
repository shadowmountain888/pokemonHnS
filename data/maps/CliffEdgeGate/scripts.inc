CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "{JPN}しってる? この さき に\n"
	.string "{JPN}サファリゾーン が あるんだ.\p"
	.string "{JPN}とっても たのしいよ!\n"
	.string "{JPN}いろんな しゅるい の\l"
	.string "{JPN}ポケモン が みられて つかみほうだい!\p"
	.string "{JPN}いかない りゆう なんて ないよね?\n"
	.string "{JPN}この さき だよ.$"

CliffEdgeGate_Text_Expectations:
	.string "{JPN}みんな が たのしみに してるのは\n"
	.string "{JPN}うれしいんだけど.\p"
	.string "{JPN}うけつけ の おねえさん が\n"
	.string "{JPN}ちょっと おおげさ すぎて...\p"
	.string "{JPN}きたい しすぎちゃ だめだよ!$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "{JPN}すべて が スリリング!\n"
	.string "{JPN}やせい の ポケモン を さがそう!\l"
	.string "{JPN}えんちょう バオバ の サファリゾーン\l"
	.string "{JPN}ついに オープン!$"

