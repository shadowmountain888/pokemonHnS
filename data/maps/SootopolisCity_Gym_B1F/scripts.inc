SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_BRIAN, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_HARRY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_ELLEN, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_CARRIE, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_JIMMY, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "{JPN}わたしたちのリーダー アダンから\n"
	.string "{JPN}まなんだ すばらしいわざを\lみせてあげる!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "{JPN}アダン...\nゆるして...$"
SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "{JPN}ゆかの タイルを ぜんぶ われたら\n"
	.string "{JPN}どうなるか みててね$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "{JPN}ここまで きたのね でも アダンには\n"
	.string "{JPN}あえないわよ\p"
	.string "{JPN}わたしに まけちゃったらね!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "{JPN}つよいのね!\n"
	.string "{JPN}かわいい かおに だまされたわ!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "{JPN}アダンに いちげきで やられないくらい\n"
	.string "{JPN}つよいかもしれないわね$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "{JPN}アダンが しきしている\n"
	.string "{JPN}バトルを みていると...\p"
	.string "{JPN}その うつくしさに みせられて\n"
	.string "{JPN}トレーナーに なったの$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "{JPN}あなたの バトルは\n"
	.string "{JPN}わたしより うつくしかった...$"
SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "{JPN}あなたの バトルの エレガンスは\n"
	.string "{JPN}すばらしいわ\p"
	.string "{JPN}ああ...\n"
	.string "{JPN}ポケモンに であえて\nほんとうに よかった$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "{JPN}バトルが どんなに きびしいか\n"
	.string "{JPN}おしえてあげるわ$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "{JPN}あら\n"
	.string "{JPN}つよいのね$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "{JPN}いいことを おしえてあげる\p"
	.string "{JPN}アダンに あいたいなら\n"
	.string "{JPN}ゆかの タイルを ひとつずつ\lふんでいかなくちゃだめよ$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "{JPN}ホウエンちほうで さいこう\n"
	.string "{JPN}レベルの ポケモンジム...\p"
	.string "{JPN}それが ここ ルネジムよ$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "{JPN}なんて たかい レベルなの!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "{JPN}つよい ジムに いることに まんぞくするより\n"
	.string "{JPN}ほかの ばしょで しゅぎょうしたほうが\l"
	.string "{JPN}もっと つよくなれると おもうの\l"
	.string "{JPN}そのうえ たのしそうよね$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "{JPN}わたしは アダンと いっしょに\n"
	.string "{JPN}ポケモンを きたえているの\p"
	.string "{JPN}あまくみちゃ だめよ$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "{JPN}まけちゃった...$"
SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "{JPN}あなた みこみが ありそうね\n"
	.string "{JPN}ここに のこって わたしたちと\lしゅぎょうしない?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "{JPN}こおりの うえを せんを\n"
	.string "{JPN}ふまずに エレガントに すべる...\p"
	.string "{JPN}そんな パフォーマンスを する\n"
	.string "{JPN}トレーナーは うつくしいわね!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "{JPN}ちょっと しつれいね?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "{JPN}あたりまえのことだけど トレーナーとして\n"
	.string "{JPN}どのくらい つよいかは\l"
	.string "{JPN}ねんれいとは かんけいないのよ$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "{JPN}ポケモンと いっしょにいると\n"
	.string "{JPN}あっ!というまに じかんが\lすぎちゃうの$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "{JPN}あっ!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "{JPN}あっ!というまに\n"
	.string "{JPN}だめなことは わすれられたら\lいいのにな$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "{JPN}よかったら とても めずらしい\n"
	.string "{JPN}ポケモンと バトルできるわよ$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "{JPN}あらあら! わたしの ポケモン\n"
	.string "{JPN}よく みれた?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "{JPN}アダンが わたしの かわいい\n"
	.string "{JPN}ポケモンを ほめてくれたから\n"
	.string "{JPN}このジムに きたの\p"
	.string "{JPN}ああ もし わかいころに\nアダンに あっていたら...$"
SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "{JPN}くすくす...\n"
	.string "{JPN}あなたの きびしい かおも\nチャーミングね$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "{JPN}あらあら\n"
	.string "{JPN}てかげん しすぎちゃった$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "{JPN}あなたでも アダンには\n"
	.string "{JPN}てが でないでしょうね\nくすくす...$"
