VioletCity_Mart_MapScripts::
	.byte 0

VioletCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VioletCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Mart_EventScript_Rocker::
	lock
	faceplayer
	msgbox VioletCity_Mart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Mart_Text_Granny:
	.string "{JPN}つかまえたばかりじゃ\n"
	.string "{JPN}よわいポケモンでもそだてりゃ\l"
	.string "{JPN}いつかはつよくなりますよ\p"
	.string "{JPN}だいじなのはポケモンへの\n"
	.string "{JPN}あいじょうだとおもいます$"
VioletCity_Mart_Text_CooltrainerM:
	.string "{JPN}ポケモンもどうぐもてるけど\n"
	.string "{JPN}キズぐすりとかどくけしとか\l"
	.string "{JPN}ひとがつくったどうぐは\l"
	.string "{JPN}つかいかたがわからんようだな$"