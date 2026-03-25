SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_GRUNT_26, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end
	
SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge:
	.string "{JPN}ごめんなさい あなたは\n"
	.string "{JPN}ポケモンセンターチャレンジを\lプレイちゅうです!$"

SSTidalRooms_Text_TakeRestOnBed:
	.string "{JPN}ベッドが あるね...\n"
	.string "{JPN}ちょっと やすんでいこう$"

SSTidalRooms_Text_ColtonIntro:
	.string "{JPN}わたしは よく ミナモシティに\n"
	.string "{JPN}いくんです.\p"
	.string "{JPN}コンテストを みるのが\nすきなんですよ.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "{JPN}たのしい しあいでした!$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "{JPN}つぎの コンテストでは どんな\n"
	.string "{JPN}ポケモンが みられるか そうぞう\l"
	.string "{JPN}するだけで わくわくします!$"

SSTidalRooms_Text_MicahIntro:
	.string "{JPN}きみの ともだちは つよいの?$"

SSTidalRooms_Text_MicahDefeat:
	.string "{JPN}きみの ともだちは たしかに\nつよいね.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "{JPN}ともだちは にんげんじゃなくても\n"
	.string "{JPN}いいんだ.\lぼくには ポケモンが たいせつな\lともだちさ!$"

SSTidalRooms_Text_ThomasIntro:
	.string "{JPN}こども...\n"
	.string "{JPN}ドアを ノックしたのかい?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "{JPN}まけは あわてず さわがず\n"
	.string "{JPN}うけいれるものだ.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "{JPN}どんな じょうきょうでも\n"
	.string "{JPN}どうじなければならぬのが\lジェントルマンの こころえだ.$"

SSTidalRooms_Text_JedIntro:
	.string "{JPN}ジェド: ちょっと はずかしいけど...\n"
	.string "{JPN}ぼくたちの らぶらぶパワーを\lみせてあげるよ!$"

SSTidalRooms_Text_JedDefeat:
	.string "{JPN}ジェド: はあ...$"
SSTidalRooms_Text_JedPostBattle:
	.string "{JPN}ジェド: ぼくたちの らぶらぶパワーが\n"
	.string "{JPN}つうじなかったのは はじめてだ!\l"
	.string "{JPN}きみは すごい トレーナーだね!$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "{JPN}ジェド: ポケモンが 1ぴきだけ?\n"
	.string "{JPN}それじゃ さびしすぎるよ!$"

SSTidalRooms_Text_LeaIntro:
	.string "{JPN}レア: ちょっと ばかみたいだけど...\n"
	.string "{JPN}わたしたちの らぶらぶパワーを\lみせてあげる!$"

SSTidalRooms_Text_LeaDefeat:
	.string "{JPN}レア: あーあ!$"

SSTidalRooms_Text_LeaPostBattle:
	.string "{JPN}レア: しんじられない!\n"
	.string "{JPN}わたしたちの らぶらぶパワーが\l"
	.string "{JPN}しっぱい...\lあなた すごい トレーナーね!$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "{JPN}レア: たたかいたかったのに...\n"
	.string "{JPN}あなた ポケモンを 2ひきも\lもってないのね...$"
SSTidalRooms_Text_GarretIntro:
	.string "{JPN}ああ ちょうど よいところに\n"
	.string "{JPN}きたな.\p"
	.string "{JPN}たいくつしていたのだ.\nわたしの あいてを してくれ.$"

SSTidalRooms_Text_GarretDefeat:
	.string "{JPN}...それで じゅうぶんだ$"
SSTidalRooms_Text_GarretPostBattle:
	.string "{JPN}ちちうえに ヨットを かって\n"
	.string "{JPN}もらおうかな.\l"
	.string "{JPN}わたしと ポケモンのための\lヨットを!$"

SSTidalRooms_Text_NaomiIntro:
	.string "{JPN}あら かわいい トレーナーさん.\n"
	.string "{JPN}おちゃでも のみませんか?\l"
	.string "{JPN}それとも バトルします?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "{JPN}そうですか.\n"
	.string "{JPN}かつどうてきな かたなのね.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "{JPN}ごうかせんでの せかいりょこうには\n"
	.string "{JPN}みりょくが あるわね...\p"
	.string "{JPN}でも ホウエンちほうを\n"
	.string "{JPN}フェリーで まわるのも\lすてきかも しれないわ$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "{JPN}あ... こんにちは! わたし...\n"
	.string "{JPN}わたし あやしいことなんて\l"
	.string "{JPN}してないから!\p"
	.string "{JPN}あ... これ もらって! ただで!\p"
	.string "{JPN}それ... ほんとうに だれかから\nひったくったり なんて\lしてないよ! そんなこと\lぜったい しないから!\lきれいだから つかって!$"

SSTidalRooms_Text_ExplainSnatch:
	.string "{JPN}よこどりは てきや みかたが\n"
	.string "{JPN}つかおうとした いりょくな\l"
	.string "{JPN}わざのこうかを よこどりします.$"

