MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "{JPN}やあ トレーナー!\n"
	.string "{JPN}スーパーつりざおは\l"
	.string "{JPN}ほんとうにスーパーだよ!\p"
	.string "{JPN}をいおうと これなら\n"
	.string "{JPN}うみののポケモンだって\l"
	.string "{JPN}つれちゃうんだ!\pどうだい?\nほしいだろう?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "{JPN}そうそう そのとおり!\n"
	.string "{JPN}やっぱりスーパーつりざおは\lほんとうにスーパーだからね!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "{JPN}みずがあるところなら \n"
	.string "{JPN}つりざおをたらしてみて\lなにがつれるかためしてね!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "{JPN}えっ?\n"
	.string "{JPN}つりはすきじゃないのかい?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "{JPN}スーパーつりざおで\n"
	.string "{JPN}うみののポケモンを\lねらってみてくれ.$"

