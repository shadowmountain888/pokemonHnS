VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "{JPN}ミツル: きみに まけちゃったけど\n"
	.string "{JPN}{PLAYER} もう おちこんで\l"
	.string "{JPN}ないよ.\p"
	.string "{JPN}だって ぼくには あたらしい\n"
	.string "{JPN}もくひょうが できたんだ.\l"
	.string "{JPN}ラルトスと いっしょに ポケモン\l"
	.string "{JPN}ジムに ちょうせんして\l"
	.string "{JPN}すごい トレーナーに なるんだ.\p"
	.string "{JPN}みていてよ {PLAYER}.\n"
	.string "{JPN}きみより つよく なってみせる.\pそのときは もういちど\nしょうぶを もうしこむからね.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "{JPN}ミツル: みていてよ {PLAYER}.\n"
	.string "{JPN}きみより つよく なってみせる.\p"
	.string "{JPN}そのときは もういちど\n"
	.string "{JPN}しょうぶを もうしこむからね.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "{JPN}おじさん: おお! {PLAYER}{KUN}!\n"
	.string "{JPN}ミツルは となりに いるよ.\p"
	.string "{JPN}でもね きみに はなさなければ\n"
	.string "{JPN}ならない ことが あるんだ.\p"
	.string "{JPN}この しぜんかんきょうが\n"
	.string "{JPN}ミツルの けんこうに とても\l"
	.string "{JPN}よいえいきょうを あたえているよ.\p"
	.string "{JPN}たぶん かんきょうだけじゃなくて\n"
	.string "{JPN}ポケモンが あのこに きぼうを\lあたえているのかも しれないね.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "{JPN}ミツルは いって しまった...\n"
	.string "{JPN}ひとりで でかけて しまった...$"
VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "{JPN}おじさん: そうなのか?\n"
	.string "{JPN}ミツルが そんなに とおくまで\l"
	.string "{JPN}ひとりで いって しまったのか...\p"
	.string "{JPN}まあ たいしたものだ--\n"
	.string "{JPN}あいつは わたしの おとうとの\lむすこだからな$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "{JPN}ワンダ: あなたは?\n"
	.string "{JPN}ああ そうか わかったわ!\p"
	.string "{JPN}あなたが ミツルから きいていた\n"
	.string "{JPN}{PLAYER}ね.\p"
	.string "{JPN}わたしは ミツルの いとこよ.\n"
	.string "{JPN}はじめまして!\p"
	.string "{JPN}ミツルは ここに きてから\n"
	.string "{JPN}ずっと げんきで けんこうに\lなったと おもうの.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "{JPN}ワンダ: ミツルの ことは\n"
	.string "{JPN}しんぱい しないで.\l"
	.string "{JPN}きっと だいじょうぶよ.\p"
	.string "{JPN}わたしの かわいい いとこだし\nポケモンも いっしょに いるもの.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "{JPN}きみの おかげで まいにち\n"
	.string "{JPN}かのじょに あえるように なったよ.\l"
	.string "{JPN}うれしいって? もちろんさ!$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "{JPN}むすめの かれしは とても\n"
	.string "{JPN}ねっしんで じょうねつてきな\l"
	.string "{JPN}ひとなのよ.\p"
	.string "{JPN}むすめに あうために\n"
	.string "{JPN}やすむことなく トンネルを\l"
	.string "{JPN}ほっているの.\pむすめも ちょっと しんぱいで\nよく トンネルの ようすを\lみに いっているのよ.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "{JPN}すごいのよ.むすめの かれしは\n"
	.string "{JPN}てで トンネルを ほっていたの!\p"
	.string "{JPN}ほんとうに しんじられないわ!$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "{JPN}もし ミツルに なにかあったら\n"
	.string "{JPN}トウカの りょうしんに\l"
	.string "{JPN}あわせる かおが ない...$"
VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "{JPN}ミツルが サイユウに\n"
	.string "{JPN}いたですって?\p"
	.string "{JPN}トウカシティの りょうしんが\nきいたら びっくりするでしょうね!$"

