MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます\p"
	.string "{JPN}この ふしぎなカードを もっていると\n"
	.string "{JPN}フレンドリーショップの アンケートで\p"
	.string "{JPN}いろいろな トレーナーを ルネシティに\n"
	.string "{JPN}よぶことが できますよ!\p"
	.string "{JPN}...ないしょで ひとつ アンケートの\n"
	.string "{JPN}あいことばを おしえて あげましょう\p"
	.string "{JPN}すごい トレーナー\n"
	.string "{JPN} くれ くれ\p"
	.string "{JPN}このことばを アンケートに かいて\n"
	.string "{JPN}ぜひ ジョイスポットと\l"
	.string "{JPN}つうしんして みてください!$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "{JPN}ふしぎなおくりもの を ごりよう\n"
	.string "{JPN}いただき ありがとう ございます\p"
	.string "{JPN}ルネシティに トレーナーが\n"
	.string "{JPN}きている ようですよ\p"
	.string "{JPN}ぜひ たいせんを\n"
	.string "{JPN}たのしんで くださいませ!\p"
	.string "{JPN}ほかの あいことば でも\n"
	.string "{JPN}べつの トレーナーが よべますので\p"
	.string "{JPN}あいことばを いろいろと\n"
	.string "{JPN}さがして みて ください$"
