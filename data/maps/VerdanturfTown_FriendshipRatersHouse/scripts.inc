VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "{JPN}きみのポケモンを\n"
	.string "{JPN}みせてくれるかい.\p"
	.string "{JPN}どのくらい きみのことを\n"
	.string "{JPN}すきになっているか\lしらべてみよう.\pふむ.\nきみのポケモンは...$"
VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "{JPN}あなたを したっています.\n"
	.string "{JPN}これいじょう あいする ことは\l"
	.string "{JPN}できないでしょう.\lみていて うれしく なります.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "{JPN}とても しあわせ そうです.\n"
	.string "{JPN}あきらかに あなたを\lとても すきに なっています.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "{JPN}あなたを かなり\n"
	.string "{JPN}すいています.\lすこし あまえたがって\lいる ようです.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "{JPN}あなたに なれてきて います.\n"
	.string "{JPN}あなたを しんじている\lようです.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "{JPN}まだ あまり\n"
	.string "{JPN}なれていません.\lあいしても きらいとも\lおもっていません.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "{JPN}とても けいかい しています.\n"
	.string "{JPN}めに こわい\l"
	.string "{JPN}きょうぼうさが あります.\lあなたを あまり\lすいていません.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "{JPN}これは いいにくいことなんじゃが...\p"
	.string "{JPN}きみのポケモンは きみのことを\n"
	.string "{JPN}ひどく きらっているようじゃ.\pそれでも へいきなのかね?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "{JPN}ピカチュウ: ピカ ピカ!$"

