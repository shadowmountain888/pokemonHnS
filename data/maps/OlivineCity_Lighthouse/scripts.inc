.set LOCALID_LIGHTHOUSE_JASMINE, 12
.set LOCALID_LIGHTHOUSE_AMPHAROS, 13

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMBulkUp::
    finditem ITEM_TM_BULK_UP
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "{JPN}ひとびとはこのとうだいで\nしゅぎょうするんだ\pなかにはトレーナーがたくさんいて\nのぼるのはたいへんだぞ$"
OlivineLighthouse_Text_1FPokefanF:
	.string "{JPN}むかしはポケモンがよるに\nアサギのまわりのうみをてらしてた\pそのりっぱなポケモンをしのんで\nとうだいがたてられたのよ$"@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "{JPN}うみのおとこはいつでも\nたたかいをもとめているんだ！$"
OlivineLighthouse_Text_SailorHueyBeaten:
	.string "{JPN}うわー！\nまけたー！$"
OlivineLighthouse_Text_SailorHueyAfter:
	.string "{JPN}そのつよさ！おれといっしょに\nうみをこうかいしないか？$"
OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "{JPN}ん？ここはあそびにくる\nばしょじゃないよ$"
OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "{JPN}おお！きみはほんきで\nきているのだな$"
OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "{JPN}うえのほうにとうだいを\nてらすポケモンがいる\pだがいまはびょうきで\nふつうにはなおらないらしい$"@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "{JPN}なんでここにいるんだ？\nやじうまか？かえったほうがいい！$"
OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "{JPN}きみはほんとうにびょうきの\nポケモンをしんぱいしてるんだな.$"
OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "{JPN}いったいどうやってあがるんだ？\pびょうきのポケモンに\nあいにいきたいのに.$"
OlivineLighthouse_Text_SailorTerrellSeen:
	.string "{JPN}せんいんはやさしくてつよいんだ\nきみはどうかな？$"
OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "{JPN}きみはやさしくてつよいな.$"
OlivineLighthouse_Text_SailorTerrellAfter:
	.string "{JPN}アサギにもどるたびに\nジムによっていくんだ\pジムリーダーのポケモンタイプが\nきづかないうちにかわってた$"
OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "{JPN}せかいをたびしてポケモンを\nきたえているのです$"
OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "{JPN}.はあ.もっとしゅぎょうが\nひつようですな.$"
OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "{JPN}ミカンはまえはイワークなど\nいわタイプをつかっていました$"@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "{JPN}ミカンはここのポケモンが\nしんぱいでしかたがないんだ\pさいきんはえがおもみせない$"
OlivineLighthouse_Text_SailorKentBeaten:
	.string "{JPN}おれもえがおになれないよ.$"
OlivineLighthouse_Text_SailorKentAfter:
	.string "{JPN}びょうきといえばタンバには\nいいくすりやがあるときいたぞ$"
OlivineLighthouse_Text_LassConnieSeen:
	.string "{JPN}ミカンはこのまちの\nジムリーダーよ！\pわたしがつれてかえるの！\pじゃまはさせないわ！$"
OlivineLighthouse_Text_LassConnieBeaten:
	.string "{JPN}あああ！わたしのポケモン！$"
OlivineLighthouse_Text_LassConnieAfter:
	.string "{JPN}そうね.じぶんのポケモンが\nきずついたらだれでもしんぱい\pここのポケモンのためにいのるから\nミカンはジムにもどっていいのよ$"@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "{JPN}ミカンとたたかいたかったんだが\nいまはむりみたいだな\pそれじゃあきみはどうだ？$"
OlivineLighthouse_Text_SailorErnestBeaten:
	.string "{JPN}うおお.つよすぎるぜ！$"
OlivineLighthouse_Text_SailorErnestAfter:
	.string "{JPN}ジムリーダーはただつよいだけ\nじゃだめなんだな\pやさしさもひつようなんだ$"
OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "{JPN}ここはけっこうたかいぞ\nとりポケモンのちょうしもばっちりだ$"
OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "{JPN}あちゃー.おちちゃった.$"
OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "{JPN}ポケモンはタンバシティで\nそらをとぶをおぼえたんだ\pまけたからそらをとんで\nうみをわたってかえるよ.$"@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "{JPN}ミカン: ...このコいつも\nうみをてらしてくれてたの\p"
	.string "{JPN}...でも\nいきなりぐったりして\lいきもたえだえ...\p"
	.string "{JPN}...うみのむこうタンバには\nすごいくすりやさんが\l"
	.string "{JPN}いるそうですけど...\p"
	.string "{JPN}あたしアカリちゃんのそばを\nはなれるわけにはいかないし...\p"
	.string "{JPN}...あのうおねがいです\nあたしのかわりにくすりを\l"
	.string "{JPN}もらってきていただけませんか?\p"
	.string "{JPN}こちらのいりぐちは\nあけておきますので...\p$"
OlivineLighthouse_Text_JasmineGetMedicine:
	.string "{JPN}...ああのうおねがいです\nあたしのかわりにくすりを\l"
	.string "{JPN}もらってきてくださいね?\p$"
OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "{JPN}タンバシティにすばらしい\nくすりやがあるの.\p.でもうみのむこうだし.\nデンリュウをひとりにできない.\p.くすりをとってきて\nもらえませんか？おねがいします$"
OlivineLighthouse_Text_JasmineCureAmphy:
	.string "{JPN}ミカン: ...そのくすりで\nアカリちゃんなおせるのですか?$"
OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playse MUS_HEAL
	waitse
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{JPN}{PLAYER}はミカンに\nひでんのくすりをわたした$"
OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "{JPN}ミカン: ...ああの\nきをわるくしないでくださいね\p"
	.string "{JPN}アカリちゃん\nあたしいがいのひとから\lものをうけとらないから...\p$"
OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "{JPN}ミカン: .........\p"
	.string "{JPN}アカリちゃんぐあいはどう?\p$"
OlivineLighthouse_Text_JasmineThankYou:
	.string "{JPN}ミカン: ...ああよかった\nほんとによかったです\p"
	.string "{JPN}ありがとうございます\nあなたのおかげです\p"
	.string "{JPN}...ではあたし\nジムにもどります\p$"
OlivineLighthouse_Text_JasmineISee:
	.string "{JPN}ミカン: ...そうですか\p$"
OlivineLighthouse_Text_AmphyPalPaloo:
	.string "{JPN}アカリちゃん: .........\n...ぱ...ぱるう\p$"
OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "{JPN}いきをするのもくるしそう$"
OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "{JPN}アカリちゃん: パルッ!パルルッ!\p$"
