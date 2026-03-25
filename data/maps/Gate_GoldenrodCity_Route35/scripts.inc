Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "{JPN}ちょっと きみ! おにいさんに\n"
	.string "{JPN}たのみごと きいてくれる?\p"
	.string "{JPN}この てがみつきの ポケモンを\n"
	.string "{JPN}ともだちに とどけてくれる?\p"
	.string "{JPN}かれは 31ばんどうろに いるんだ$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "{JPN}やってくれる? さいこうだ!\n"
	.string "{JPN}ありがとう きみ!\p"
	.string "{JPN}ぼくの ともだちは ふとっちょで\n"
	.string "{JPN}いつも ねむっている やつなんだ\pすぐに わかるよ!$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{JPN}{PLAYER}は てがみつきの\nポケモンを うけとった$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "{JPN}ともだちを みつけたら\n"
	.string "{JPN}てもちの さいぜんれつに\n"
	.string "{JPN}おいてくれよ!\p"
	.string "{JPN}31ばんどうろだ!\p"
	.string "{JPN}そうそう へんな きが\n"
	.string "{JPN}どうろを ふさいでたんだ\pもう どかされたかな?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "{JPN}ポケモンを もう 1ぴき\nつれていけないよ...$"
Route35GoldenrodGate_Text_RandyNeverMind:
	.string "{JPN}そう... じゃあ いいよ...$"
Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "{JPN}ありがとう きみ!\n"
	.string "{JPN}とどけてくれたんだね!\p"
	.string "{JPN}これは おれいだよ!$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "{JPN}ともだち ねむってただろ?\n"
	.string "{JPN}ほら いったとおりだ!$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "{JPN}ふしぎな きが どうろを\n"
	.string "{JPN}ふさいでるの\p"
	.string "{JPN}はなしかけると うごめくのよ\p"
	.string "{JPN}だれかが みずでっぽうで\nみずを かけたら やせいになったって\nきいたわ$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "{JPN}ラジオで ながれる ポケモンの\n"
	.string "{JPN}こもりうたが すきなの$"

Route35GoldenrodGate_Text_Fisher:
	.string "{JPN}せかいには なんしゅるいの\n"
	.string "{JPN}ポケモンが いるんだろう\p"
	.string "{JPN}3ねんまえ オーキドはかせは\n"
	.string "{JPN}150しゅるいって いってたけど\p"
	.string "{JPN}さいきん 400しゅるい いじょうって\n"
	.string "{JPN}きいたぞ!$"
