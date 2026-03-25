MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます\p"
	.string "{JPN}あなたの もっている\n"
	.string "{JPN}たいせん カウント カード は\p"
	.string "{JPN}おなじ カードを もっている\n"
	.string "{JPN}トレーナーと たいせん することで\l"
	.string "{JPN}せいせきが きろくされて いきます\p"
	.string "{JPN}ぜひ おなじ カードをもつ\n"
	.string "{JPN}トレーナーと たいせん してください\p"
	.string "{JPN}また ニュースを よみこむことで\n"
	.string "{JPN}ランキングを みれますので\l"
	.string "{JPN}ぜひ ごりよう ください!$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます\p"
	.string "{JPN}おめでとう ございます!\p"
	.string "{JPN}ただいま たいせんで 3しょうした\n"
	.string "{JPN}トレーナーには プレゼントを\l"
	.string "{JPN}さしあげて います!\p"
	.string "{JPN}これからも どんどん\n"
	.string "{JPN}たいせんを たのしんで ください!$"
