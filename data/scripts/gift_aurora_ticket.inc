MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます!\l"
	.string "{JPN}{PLAYER}さま ですね\p"
	.string "{JPN}あなたさま あてに\n"
	.string "{JPN}この チケットが\l"
	.string "{JPN}おくられて きました$"

sText_AuroraTicketUseAtPort:
	.string "{JPN}ミナモシティの ふなつきば で\n"
	.string "{JPN}つかえる ようですね\p"
	.string "{JPN}ぜひ ごりよう してみては\n"
	.string "{JPN}いかがでしょうか?$"

sText_AuroraTicketThankYou:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございました$"

sText_AuroraTicketBagFull:
	.string "{JPN}しかし {PLAYER}さま!\n"
	.string "{JPN}たいせつなものが いっぱい です\p"
	.string "{JPN}パソコンに あずけてから\n"
	.string "{JPN}また きてください$"
