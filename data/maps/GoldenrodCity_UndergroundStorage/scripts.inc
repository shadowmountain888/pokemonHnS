GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
	.string "{JPN}なんでここまできた？\pしかたない。\nかたづけてやる！$"
RadioTowerBasement_Text_GruntM24Beaten:
	.string "{JPN}かたづけられちまった.$"
RadioTowerBasement_Text_GruntM24After:
	.string "{JPN}ロケットだんは\nサカキさまのふっかつを\nまちつづける！\pなんでもやってやるぜ！$"
RadioTowerBasement_Text_GruntM14Seen:
	.string "{JPN}これいじょういかせねえ！\pてきにはようしゃしねえぞ\nガキだろうとな！$"
RadioTowerBasement_Text_GruntM14Beaten:
	.string "{JPN}くそったれ！$"
RadioTowerBasement_Text_GruntM14After:
	.string "{JPN}まけちまった..\pサカキさま\nゆるしてください！$"
RadioTowerBasement_Text_GruntM15Seen:
	.string "{JPN}ひゃっひゃっひゃ！\nきたなきたな！\pじゅんびはいいか？\nオレはつよくなったぞ！$"
RadioTowerBasement_Text_GruntM15Beaten:
	.string "{JPN}ひゃっひゃっひゃ！\nつよいじゃねーか！\pロケットだんは\nただのしごとだが\nひとをきずつけてるのが\nわかったぜ。\pもうやめる！\nありがとうよ。\nサカキさまごめん！$"
RadioTowerBasement_Text_GruntM15After:
	.string "{JPN}ひゃっひゃっひゃ！\nたのしかったぜ！\nおまえをわすれねーよ！$"
RadioTowerBasement_Text_DirectorIntro:
	.string "{JPN}きょくちょうだれ？なに？\nたすけにきてくれたのかい？\pありがとう！\pラジオとうは\nどうなってるんだい？\pロケットだんに\nのっとられた？\pこれをもっていきなさい\nカードキーだよ。$"
RadioTowerBasement_Text_DirectorCardKey:
    .string "{JPN}こうちょう: それを つかって\n"
	.string "{JPN}3かいの シャッターを\lあけるのじゃ$"

RadioTowerBasement_Text_DirectorAfter:
	.string "{JPN}たのむからたすけてくれ\pでんぱとうをのっとられたら\nなにをするかわからんぞ\pとくしゅなでんぱで\nポケモンをあやつるかも\pきみしかたのめるひとが\nいないんじゃ\pラジオとうをすくって\nくれ..\pそしてぜんこくの\nポケモンをたのむ！$"