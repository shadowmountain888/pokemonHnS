NationalPark_Normal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "{JPN}みて!わたしのかばん!\p"
	.string "{JPN}ポケモンずかんから きにいった\n"
	.string "{JPN}のを プリントして はったの!$"

NationalPark_Normal_Text_PokefanF:
	.string "{JPN}これは むすめから もらった\n"
	.string "{JPN}メールなの.げんきが でるわ.$"

NationalPark_Normal_Text_Teacher1:
	.string "{JPN}ちゅうもくしてください!\p"
	.string "{JPN}...あっ いつもせんせいみたいに\n"
	.string "{JPN}かんがえちゃだめですね.\p"
	.string "{JPN}あなたはポケモントレーナー\n"
	.string "{JPN}ですね.\p"
	.string "{JPN}がんばってるから \nこれをあげましょう.$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "{JPN}ポケモンに そのせんせいのツメを\n"
	.string "{JPN}もたせてごらんなさい.\p"
	.string "{JPN}バトルで ときどき さきに\nこうげきできますよ.$"

NationalPark_Normal_Text_Youngster1:
	.string "{JPN}ポケモンずかんから プリントした\n"
	.string "{JPN}シールで あそんでるんだ.$"

NationalPark_Normal_Text_Youngster2:
	.string "{JPN}かったら あいての ポケモンずかん\n"
	.string "{JPN}シールが もらえるんだ.$"

NationalPark_Normal_Text_Teacher2:
	.string "{JPN}こうえんをさんぽしますが \n"
	.string "{JPN}くさむらにははいりません.\p"
	.string "{JPN}トレーナーはいつもたたかいたがる\n"
	.string "{JPN}んです...\p"
	.string "{JPN}あなたもたくさんたたかって\nきたでしょうね.\nポケモンをかいふくしてあげます.$"

NationalPark_Normal_Text_Persian:
	.string "{JPN}ペルシアン:フフシャー!$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "{JPN}ポケモンのせかいは ふかいんだ.\p"
	.string "{JPN}まだまだ わからないことが\n"
	.string "{JPN}いっぱい あるんだ.\p"
	.string "{JPN}でも きみより ぼくのほうが\nしってるぞ!$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "{JPN}な な なんだってー?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "{JPN}おぼえることがたくさん\n"
	.string "{JPN}あります.\p"
	.string "{JPN}たとえば...\p"
	.string "{JPN}wざマシンは50しゅるい\nあります.\pこうかんしたポケモンは\nレベルアップがはやいんです.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "{JPN}わたしのポケモンは とっても\n"
	.string "{JPN}かわいいのよ.\p"
	.string "{JPN}じまんのこたちが どんなに\nすばらしいか おしえてあげる!$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "{JPN}プライドではまけないけど...$"
NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "{JPN}あなたのポケモンも なかなか\n"
	.string "{JPN}かわいいじゃない.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "{JPN}ポケモンに きらわれても\n"
	.string "{JPN}あいしつづける.\p"
	.string "{JPN}それが ファンというものだ!$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "{JPN}ぼ ぼくのポケモン!$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "{JPN}しょうぶは まけたけど\n"
	.string "{JPN}かわいさでは ゆうしょうだ.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "{JPN}なあに?なんで じーっと\n"
	.string "{JPN}みてるの?\pあ バトル?$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "{JPN}...うーん...$"
NationalPark_Normal_Text_LassKrise_After:
	.string "{JPN}わたしが かわいいから\n"
	.string "{JPN}みつめてたのかと おもった!$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "{JPN}やすらぎひろば\n"
	.string "{JPN}しぜんこうえん$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "{JPN}おしらせ\p"
	.string "{JPN}バトルは くさむらで\n"
	.string "{JPN}おねがいします.\pしぜんこうえん かんりにん$"

NationalPark_Normal_Text_TrainerTips:
	.string "{JPN}トレーナーのコツ\p"
	.string "{JPN}メールを ひらいてから\n"
	.string "{JPN}スタートボタンで プリントできる.$"
