MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます!\l"
	.string "{JPN}{PLAYER}さま ですね\p"
	.string "{JPN}あなたさま あてに\n"
	.string "{JPN}この チケットが\l"
	.string "{JPN}おくられて きました$"

sText_MysticTicketUseAtPort:
	.string "{JPN}ミナモシティの ふなつきば で\n"
	.string "{JPN}つかえる ようですね\p"
	.string "{JPN}ぜひ ごりよう してみては\n"
	.string "{JPN}いかがでしょうか?$"

sText_MysticTicketThankYou:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございました$"

sText_MysticTicketBagFull:
	.string "{JPN}しかし {PLAYER}さま!\n"
	.string "{JPN}たいせつなものが いっぱい です\p"
	.string "{JPN}パソコンに あずけてから\n"
	.string "{JPN}また きてください$"
