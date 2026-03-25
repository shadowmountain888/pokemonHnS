GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "{JPN}じてんしゃにのるのは\nかんたんですよ\lバッグでとうろくすれば\pボタンひとつです！\pもっとはやくいきたいなら\nまずていししてください！\pへんなアドバイスですが\nじてんしゃのギアは\lていしちゅうしかかえられません\pていしちゅうにRボタンをおして\nつぎにペダルをこげば\lもっとはやくはしれます！$"
GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "{JPN}はあ..\n"
	.string "{JPN}コガネにしてんをひらいたけど\l"
	.string "{JPN}じてんしゃぜんぜんうれない\p"
	.string "{JPN}どうだろう？\n"
	.string "{JPN}きみじてんしゃにのりまくって\l"
	.string "{JPN}せんでんしてくれない？$"
GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "{JPN}ほほんと？\p"
	.string "{JPN}じゃあなまえとでんわばんごう\n"
	.string "{JPN}おしえてよ\l"
	.string "{JPN}じてんしゃをかすからさ$"
GoldenrodCity_BikeShop_Text_BorrowedBicycle:
	.string "{JPN}{PLAYER}は\nじてんしゃをかりた！$"
GoldenrodCity_BikeShop_Text_Mainshop:
	.string "{JPN}カントウからひっこしてきてから\nしょうばいがたいへんなんです\lおきゃくさんにかんしゃです！\pぜひじまんのギアチェンジきのうを\nみせびらかしてくださいね？\pじてんしゃでとまっているときに\nアールボタンをおすだけです\pちゅうい！そのあとはやくなります！$"
GoldenrodCity_BikeShop_Text_Refused:
    .string "{JPN}はあ..\n"
	.string "{JPN}ひとのやさしさにふれたいよ$"
GoldenrodCity_BikeShop_Text_JustReleasedCompact:
	.string "{JPN}しんはつばい！\pいちりゅうのコンパクトじてんしゃ！$"
GoldenrodCity_BikeShop_Text_Bicycle:
    .string "{JPN}ピッカピカのじてんしゃだ！$"