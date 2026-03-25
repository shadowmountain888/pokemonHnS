.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_OLIVINE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_LickyEvo::
	msgbox VerdanturfTown_LickyEvo_Text, MSGBOX_NPC
	end

VerdanturfTown_LickyEvo_Text:
	.string "{JPN}ベロリンガは ころがって\n"
	.string "{JPN}しんかするんだよ.\nやってみて!$"

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "{JPN}おとうさんが いってたよ.\p"
	.string "{JPN}この トンネルには\n"
	.string "{JPN}おくびょうな ポケモンが\l"
	.string "{JPN}いっぱい いるんだって.\p"
	.string "{JPN}おおきな おとが すると\n"
	.string "{JPN}こわがって おおさわぎ\l"
	.string "{JPN}するんだって.\p"
	.string "{JPN}だから おおきな トンネル\n"
	.string "{JPN}こうじは やめたんだって.\pでも ひとりの おとこのひとが\nじぶんで トンネルを\lほろうと してるんだって!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "{JPN}あいする おんなのひとの\n"
	.string "{JPN}ために トンネルを ほった\l"
	.string "{JPN}おとこのひとが いたんだって.\pよく わからないけど\nすごいよね!$"

VerdanturfTown_Text_AirCleanHere:
	.string "{JPN}かぜの ながれで かざんばいは\n"
	.string "{JPN}こっちの ほうこうには\l"
	.string "{JPN}とんでこないんだよ.\p"
	.string "{JPN}ここの くうきは きれいで\n"
	.string "{JPN}おいしいから からだの よわい\lひとにも いいんだって.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "{JPN}ぼくと ポケモンは\n"
	.string "{JPN}れんしょうを かさねてるんだ.\p"
	.string "{JPN}だから この まちで\n"
	.string "{JPN}バトルテントに\lデビューすることに したんだ.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "{JPN}フレンドリィショップの\n"
	.string "{JPN}よこの どうくつ みた?\p"
	.string "{JPN}そこに いわを くだいて\n"
	.string "{JPN}むこうがわに つきぬけようと\l"
	.string "{JPN}してる ひとが いるんだ.\p"
	.string "{JPN}とおれるように なったら\n"
	.string "{JPN}いいのにな...\lカナズミシティに いきやすく\lなるからね.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "{JPN}フレンドリィショップの よこの\n"
	.string "{JPN}どうくつが トンネルに なって\l"
	.string "{JPN}むこうがわと つながったんだ.\p"
	.string "{JPN}これで カナズミシティまで\nデボンの しょうひんを\lかいに いくのが らくに なった.$"

VerdanturfTown_Text_TownSign:
	.string "{JPN}シダケタウン\p"
	.string "{JPN}かぜが ふきぬける\n"
	.string "{JPN}くさの かおりの こうげん$"

VerdanturfTown_Text_WandasHouse:
	.string "{JPN}ワンダの いえ$"

VerdanturfTown_Text_BattleTentSign:
	.string "{JPN}バトルテント シダケかいじょう\n"
	.string "{JPN}バトルを みて たのしもう!$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "{JPN}カナシダトンネル\n"
	.string "{JPN}カナズミシティと シダケタウンを\l"
	.string "{JPN}つなぐ トンネル\p"
	.string "{JPN}トンネル こうじは\nちゅうし されました.$"

