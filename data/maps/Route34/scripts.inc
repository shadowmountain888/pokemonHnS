.set LOCALID_ROUTE34_DAYCAREMAN, 12

Route34_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition: 
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end	

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end


Route34_Text_YoungsterSamuel_Seen:
	.string "{JPN}おい!オレはマンキーを\nさがしているんだ!$"

Route34_Text_YoungsterSamuel_Beaten:
	.string "{JPN}とおりがかりのやつに\nまけちまった!$"

Route34_Text_YoungsterSamuel_After:
	.string "{JPN}もっとはげしくしゅぎょうを\n"
	.string "{JPN}するぞ.\p"
	.string "{JPN}なにしろオレは\nジムリーダーになりたいんだ.$"

Route34_Text_YoungsterIan_Seen:
	.string "{JPN}クラスいちポケモンが\n"
	.string "{JPN}つよいのはオレだ!$"

Route34_Text_YoungsterIan_Beaten:
	.string "{JPN}だめだ! もっと つよい\nトレーナーが いるんだ...$"
Route34_Text_YoungsterIan_After:
	.string "{JPN}クラスのスターになるために\n"
	.string "{JPN}がんばっているんだ.$"

Route34_Text_CamperTodd_Seen:
	.string "{JPN}ポケモンをそだてるのには\n"
	.string "{JPN}じしんがあるぞ.\p"
	.string "{JPN}みてみるか?$"

Route34_Text_CamperTodd_Beaten:
	.string "{JPN}しゅぎょうをまちがえたかな?$"

Route34_Text_CamperTodd_After:
	.string "{JPN}そだてやに あずけるか\n"
	.string "{JPN}どうぐを つかってみるか...$"
Route34_Text_PicnickerGina_Seen:
	.string "{JPN}あなたトレーナー?\p"
	.string "{JPN}れんしゅうしあいしない?$"

Route34_Text_PicnickerGina_Beaten:
	.string "{JPN}あー だめ! かてないよー...$"
Route34_Text_PicnickerGina_After:
	.string "{JPN}れんしゅうあいてには\n"
	.string "{JPN}つよすぎるわ.$"

Route34_Text_OfficerKeith_Seen:
	.string "{JPN}だれだ!\n"
	.string "{JPN}なにをしているんだ?$"

Route34_Text_OfficerKeith_Win:
	.string "{JPN}つよいこどもだな.$"

Route34_Text_OfficerKeith_After:
	.string "{JPN}よし きょうもいじょうなしだ.\p"
	.string "{JPN}いいこにして\nトラブルはおこすなよ.$"

Route34_Text_OfficerKeith_Daytime:
	.string "{JPN}あやしいにんげんがいないか\n"
	.string "{JPN}みまわっているのです$"
Route34_Text_PokefanBrandon_Seen:
	.string "{JPN}そだてやからポケモンを\n"
	.string "{JPN}ひきとったばかりなんだ.\p"
	.string "{JPN}どのくらいつよくなったか\nみてみよう!$"

Route34_Text_PokefanBrandon_Beaten:
	.string "{JPN}どうしてこんなことに?$"

Route34_Text_PokefanBrandon_After:
	.string "{JPN}ポケモンがあたらしいわざを\n"
	.string "{JPN}おぼえてかえってきた.\pそれがこんらんのもとだった!$"

Route34_Text_Sign_IlexForest:
	.string "{JPN}ウバメのもり\n"
	.string "{JPN}ゲートをとおって$"

Route34_Text_Sign_Route34:
	.string "{JPN}34ばんどうろ\n"
	.string "{JPN}コガネシティーヒワダタウン\p"
	.string "{JPN}ウバメのもり そのちゅうかん$"

Route34_Text_TrainerTips:
	.string "{JPN}トレーナーのコツ\p"
	.string "{JPN}きのみのきは1にちになんども\n"
	.string "{JPN}あたらしいきのみがなります.\p"
	.string "{JPN}どのきにどのきのみがなるか\n"
	.string "{JPN}おぼえておきましょう.$"

Route34_Text_CooltrainerIrene_Seen:
	.string "{JPN}ちょっとちょっと！\n"
	.string "{JPN}あなただれなのよっ！$"
Route34_Text_CooltrainerIrene_Beaten:
	.string "{JPN}アイリーン:うう!つよすぎる!$"

Route34_Text_CooltrainerIrene_After1:
	.string "{JPN}アイリーン:あねのケイトが\n"
	.string "{JPN}かたきをとってくれる!$"

Route34_Text_CooltrainerIrene_After2:
	.string "{JPN}アイリーン:このビーチって\n"
	.string "{JPN}すてきでしょ?\pわたしたちの\nひみつのばしょなの!$"

Route34_Text_CooltrainerJenn_Seen:
	.string "{JPN}ちょっとちょっと！\n"
	.string "{JPN}なにしにきたのよっ！$"
Route34_Text_CooltrainerJenn_Beaten:
	.string "{JPN}ジェン:アイリーン!\nごめんなさい!$"

Route34_Text_CooltrainerJenn_After1:
	.string "{JPN}ジェン:ちょうしにのるな!\n"
	.string "{JPN}あねのケイトはつよいのよ!$"

Route34_Text_CooltrainerJenn_After2:
	.string "{JPN}ジェン:たいようのひかりが\n"
	.string "{JPN}からだをつよくするのよ.$"

Route34_Text_CooltrainerKate_Seen:
	.string "{JPN}いもうとたちを\n"
	.string "{JPN}ずいぶんかわいがってくれたわね！$"
Route34_Text_CooltrainerKate_Beaten:
	.string "{JPN}ケイト:まさか!まけるなんて\nしんじられない.$"

Route34_Text_CooltrainerKate_GiveSoftSand:
	.string "{JPN}つよいのね\n"
	.string "{JPN}まけたわかんぺきに..\p"
	.string "{JPN}これをあげるわ！$"
Route34_Text_CooltrainerKate_After:
	.string "{JPN}ごめんなさい\n"
	.string "{JPN}いきなりたたかいをいどんで\p"
	.string "{JPN}だれもこないとおもってたから\n"
	.string "{JPN}すこしびっくりしたの$"

Route34_Text_Sign_DayCare:
	.string "{JPN}ここはそだてや\n"
	.string "{JPN}あなたのポケモンそだてます$"