VioletCity_Gym_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_DOUBLE_TEAM
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "{JPN}ハヤト: おれがキキョウジム\nリーダーのハヤト!\p"
	.string "{JPN}せけんでは\nひこうタイプのポケモンなんか\lでんげきでいちころ..."
	.string "{JPN}\lそんなふうにばかにする\p"
	.string "{JPN}おれはそれがゆるせない!\p"
	.string "{JPN}おおぞらをかれいにまう\nとりポケモンのほんとうのすごさ\l"
	.string "{JPN}おもいしらせてやるよ!\p$"
VioletGym_Text_Falkner_WinLoss:
	.string "{JPN}ハヤト: ...ちくしょう\nとうさんがたいせつにしていた\l"
	.string "{JPN}ポケモンが...\p"
	.string "{JPN}だがまけたものはしかたない\nジムをとっぱしたあかしとして\l"
	.string "{JPN}ポケモンリーグこうにんの\lジムバッジをもっていけよ!\p"
	.string "{JPN}おれからきみにおくるのは\nこのウイングバッジだ!\p$"
VioletGym_Text_ReceivedZephyrBadge:
	.string "{JPN}{PLAYER}はハヤトから\nウイングバッジをもらった!$"
VioletGym_Text_Falkner_BadgeExplain:
	.string "{JPN}ハヤト: そのバッジがあれば\nひとからもらったポケモンでも\l"
	.string "{JPN}レベル20までのポケモンが\lいうことをきくようになるだろう\p"
	.string "{JPN}さらにひでんわざのいわくだきが\nつかえるようにもなるんだ\p"
	.string "{JPN}そしておれからは\nこのわざマシンをあげよう\p$"
VioletGym_Text_Falkner_TMExplain:
	.string "{JPN}ハヤト: わざマシンをつかえば\nいっしゅんでポケモンに\l"
	.string "{JPN}わざをおしえることができる!\p"
	.string "{JPN}ただしつかいすてだから\nよくかんがえてつかわないとな\p"
	.string "{JPN}ちなみにわざマシン51のなかには\nはねやすめがはいっている\p"
	.string "{JPN}これはさいだいたいりょくの\nはんぶんのりょうを\l"
	.string "{JPN}かいふくさせられるわざだ!\p"
	.string "{JPN}このさきいろんなまちに\nポケモンジムがあるから\l"
	.string "{JPN}ゆうこうにかつようしてくれ\p"
	.string "{JPN}つぎは...\nそうだなヒワダタウンにでも\lいってみるといいかもな$"
VioletGym_Text_Falkner_AfterFight:
	.string "{JPN}ハヤト: このさきいろんなまちに\nポケモンジムがあるから\l"
	.string "{JPN}そこでうでだめしをするといい\p"
	.string "{JPN}つぎは...\nそうだなヒワダタウンにでも\lいってみるといいかもな\p"
	.string "{JPN}おれはさいきょうの\nとりつかいになるため\l"
	.string "{JPN}ポケモンとおのれをきたえるよ!$"
VioletGym_Text_Falkner_Rematch:
	.string "{JPN}してんのう せいはの\nおめでとう！\pおれの ひこうタイプポケモンも\nもっと きたえたんだ\pもういちど おおぞらの ちからに\nちょうせんしてみるか？$"
VioletGym_Text_Falkner_RematchLoss:
	.string "{JPN}うわー.. また まけちまった\pおれは さいきょうの とりつかいに\nなるため もっと しゅぎょうするぞ！$"
VioletGym_Text_BirdKeeperRod_Seen:
	.string "{JPN}キーワードはこんじょうだ！\pここにいるやつらは\nとりポケモンマスターになるため\nひるもよるもしゅぎょうしてるぜ！\pかかってこい！$"
VioletGym_Text_BirdKeeperRod_Beaten:
	.string "{JPN}ガーッ！$"
VioletGym_Text_BirdKeeperRod_After:
	.string "{JPN}ハヤトのうでまえは\nほんものだからな！\pおれにかったくらいで\nちょうしにのるなよ！$"
VioletGym_Text_BirdKeeperAbe_Seen:
	.string "{JPN}きみがハヤトと\nたたかうだけのちからが\nあるかみせてもらうぜ！$"
VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "{JPN}そんなばかな！$"
VioletGym_Text_BirdKeeperAbe_After:
	.string "{JPN}しんまいトレーナーに\nまけるなんてじょうだんじゃない.$"
VioletGym_Text_GymGuide_Intro:
	.string "{JPN}おーっす!\nみらいのチャンピオン!\p"
	.string "{JPN}ジムリーダーのハヤトに\nちょうせんしにきたんだろう?\p"
	.string "{JPN}だーいかんげい!\p"
	.string "{JPN}...といいたいところだが\nちょっとまった!\p"
	.string "{JPN}このまちには\nマダツボミのとうという\lしゅぎょうのばしょがあるんだ\p"
	.string "{JPN}そこのしゅぎょうに\nたえられるぐらいでないと\l"
	.string "{JPN}ジムにちょうせんするなんて\lまだまだはやいだろうなあ\p"
	.string "{JPN}はっはっは!$"
VioletGym_Text_GymGuide_Win:
	.string "{JPN}ナイスファイト!\nそのちょうしでいっきに\lポケモンチャンピオンだぜ!$"
VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "{JPN}キキョウシティポケモンジム$"
VioletCity_Gym_Text_GymStatueCertified:
	.string "{JPN}キキョウシティポケモンジム\p"
	.string "{JPN}ジムリーダーハヤト\nにんていトレーナー!\l{PLAYER}$"
