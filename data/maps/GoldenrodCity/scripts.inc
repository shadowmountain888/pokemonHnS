.set LOCALID_GOLDENROD_ROCKET_SCOUT, 11

GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SKILL_SWAP
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	playbgm MUS_HG_ROCKET_TAKEOVER, TRUE
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_MusicNotYet::
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "{JPN}ここはコガネジムよ！\pジムリーダーのアカネは\nいまいないの。ラジオとうに\lいるかもしれないわ。$"
GoldenrodCity_Text_Woman:
	.string "{JPN}わたし まえは アカネの\n"
	.string "{JPN}ジムで しゅぎょうしてたの\l"
	.string "{JPN}でも なきごえで あたまが\lいたくなっちゃって$"

GoldenrodCity_Text_HikerDay:
	.string "{JPN}ゲームコーナーにはいったとき\nよるだったのに..いったい\lどのくらいいたんだ？！$"
GoldenrodCity_Text_HikerNight:
	.string "{JPN}ゲームコーナーにはいったとき\nひるだったのに..いったい\lどのくらいいたんだ？！$"
GoldenrodCity_Text_Snubbull:
	.string "{JPN}ブルー:ブルーーーーー！$"
GoldenrodCity_Text_MrMime:
	.string "...$"
GoldenrodCity_Text_ElmCall:
	.string "{JPN}ウツギはかせ:もしもし{PLAYER}？\nタマゴはかえったかね？\pかえったらわすれずに\nけんきゅうじょにもってきて\lほしいんだ！$"
GoldenrodCity_Text_PokefanM:
	.string "{JPN}ここはとうがふるくなって\n"
	.string "{JPN}たおれそうになったのを\l"
	.string "{JPN}さいしんのラジオきょくにしたんだ$"
GoldenrodCity_Text_Youngster1:
	.string "{JPN}じてんしゃやさんが\n"
	.string "{JPN}あたらしくできたらしいけど\l"
	.string "{JPN}どこにあんの？\p"
	.string "{JPN}ぜんぜんみつかんない..$"
GoldenrodCity_Text_CooltrainerF1:
	.string "{JPN}あのくろずくめのひとって\n"
	.string "{JPN}ロケットだんのまねしてるのかしら？\l"
	.string "{JPN}おかしなひと！$"
GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "{JPN}あのくろずくめのひとって\n"
	.string "{JPN}ほんとにロケットだんだったの？\l"
	.string "{JPN}いまでもしんじられないわ$"
GoldenrodCity_Text_CooltrainerF2:
	.string "{JPN}コガネシティのラジオとうは\nこのまちのシンボルよね。\pいまキャンペーンやってるの。\pクイズにこたえられれば\nラジオをもらえるのよ。$"
GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "{JPN}あら あなたのポケギアは\nもうラジオがきけるのね！$"
GoldenrodCity_Text_Youngster2:
	.string "{JPN}へへへ..\n"
	.string "{JPN}ひゃっかてんのちかそうこで\l"
	.string "{JPN}かくれんぼしてたらおこられた$"
GoldenrodCity_Text_Lass:
	.string "{JPN}あのなかのひとが\nポケモンのなまえを\lうらなってくれるの。\pなまえをかえることも\nできるのよ。$"
GoldenrodCity_Text_Gramps:
	.string "{JPN}ふう！このまちはおおきくて\nなにがどこにあるかわからん！$"
GoldenrodCity_Text_RocketScout1:
	.string "{JPN}ここがラジオとうか..$"
GoldenrodCity_Text_RocketScout2:
	.string "{JPN}なんだよおまえむこういけ！$"
GoldenrodCity_Text_Rocket1:
	.string "{JPN}じゃまするな！\nうせろガキ！$"
GoldenrodCity_Text_Rocket2:
	.string "{JPN}ラジオとうをのっとって..\p"
	.string "{JPN}なんだ！\n"
	.string "{JPN}こどもにはかんけいない！$"
GoldenrodCity_Text_Rocket3:
	.string "{JPN}ポケモン? あれは ただの\n"
	.string "{JPN}かねもうけの どうぐだ!$"

GoldenrodCity_Text_Rocket4:
	.string "{JPN}もうすぐおれたちのやぼうが..\n"
	.string "{JPN}これまでながかったなぁ..$"
GoldenrodCity_Text_Rocket5:
	.string "{JPN}おらあ！\n"
	.string "{JPN}こどもがなんのようだ！？\l"
	.string "{JPN}あっちいけー！$"
GoldenrodCity_Text_Rocket6:
	.string "{JPN}さあ ロケットだんの\n"
	.string "{JPN}きょうふを あじわえ!$"

GoldenrodCity_Text_StationSign:
	.string "{JPN}コガネシティポケモンジム$"
GoldenrodCity_Text_RadioTowerSign:
	.string "{JPN}ここはコガネラジオとう\p"
	.string "{JPN}さまざまなじょうほうを\n"
	.string "{JPN}ジョウトちほうにネットワーク$"
GoldenrodCity_Text_DeptStoreSign:
	.string "{JPN}ポケモングッズなんでもそろう！\pコガネひゃっかてん$"
GoldenrodCity_Text_GymSign:
	.string "{JPN}コガネシティポケモンジム\n"
	.string "{JPN}リーダーアカネ\l"
	.string "{JPN}ダイナマイトプリティギャル！$"
GoldenrodCity_Text_CitySign:
	.string "{JPN}コガネシティ\pにぎわいのおおがたとし$"
GoldenrodCity_Text_BikeShopSign:
	.string "{JPN}どこまでもはしろう！\nミラクルサイクル$"
GoldenrodCity_Text_GameCornerSign:
	.string "{JPN}あそびのてんごく！\pコガネシティゲームコーナー$"
GoldenrodCity_Text_NameRaterSign:
	.string "{JPN}ここはせいめいはんだんしのいえ\n"
	.string "{JPN}ポケモンのなまえうらないます$"
GoldenrodCity_Text_UndergroundNorthSign:
	.string "{JPN}ちかつうろいりぐち$"
GoldenrodCity_Text_UndergroundSouthSign:
	.string "{JPN}ちかつうろいりぐち$"
GoldenrodCity_Text_FlowerShopSign:
	.string "{JPN}はなやかびじん はなやさん$"
GoldenrodCity_Text_MoveTutorAsk:
	.string "{JPN}きみのポケモンに\nすばらしいわざを\nおしえてやろう！\pどうだ？ならってみるか？$"
GoldenrodCity_Text_MoveTutorCost:
	.string "{JPN}1000まいコインが\nひつようだ どうする？$"
GoldenrodCity_Text_MoveTutorDecline:
	.string "{JPN}そうか..ざんねんだな\nいいわざなのになあ！$"
GoldenrodCity_Text_MoveTutorWhich:
	.string "{JPN}わははっ！\nこうかいしないぞ！\pどのわざをおしえようか？$"
GoldenrodCity_Text_MoveTutorNoCash:
	.string "{JPN}いえからおかねを\nもってこないとな..$"
GoldenrodCity_Text_MoveTutorUnderstand:
	.string "{JPN}このわざをマスターすれば\nきみもいちにんまえだ！$"
GoldenrodCity_Text_MoveTutorFarewell:
	.string "{JPN}わははっ！\nげんきでやれよ しょうねん！$"
GoldenrodCity_Text_MoveTutorBut:
	.string "{JPN}で でも..$"
GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "{JPN}..コインがたりないぞ..$"