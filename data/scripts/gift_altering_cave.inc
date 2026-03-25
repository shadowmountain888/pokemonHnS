MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます!\p"
	.string "{JPN}さいきん 103ばんどうろ にある\n"
	.string "{JPN}へんげのどうくつ で\p"
	.string "{JPN}めずらしい ポケモンが でる という\n"
	.string "{JPN}うわさが ながれてる ようです\p"
	.string "{JPN}ぜひ いって たしかめて みては\n"
	.string "{JPN}いかがで しょうか?$"
