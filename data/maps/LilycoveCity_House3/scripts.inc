LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "{JPN}おや おや! あなた ひとりで\n"
	.string "{JPN}たびを しているの?\n"
	.string "{JPN}とても わかいのに えらいね!\p"
	.string "{JPN}わたしの こどもたちも\n"
	.string "{JPN}あなたを みならったほうが\n"
	.string "{JPN}いいかもね!\p"
	.string "{JPN}わたし? わたしは {POKEBLOCK}の\n"
	.string "{JPN}めいじんなの\p"
	.string "{JPN}ちょっと ほんきを だせば\nすばらしい {POKEBLOCK}を\nつくれるのよ\nわたしから {POKEBLOCK}の\nめいじんぎを まなんでみない?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "{JPN}あら? ほんとうに いいの?\p"
	.string "{JPN}なんでも ひとりで やろうと\n"
	.string "{JPN}しちゃ だめよ!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "{JPN}あら いいこね! あたまが いいわ\n"
	.string "{JPN}ながい はなしに なるから\n"
	.string "{JPN}よく きいてね!\p"
	.string "{JPN}じゅんびは いい?\p"
	.string "{JPN}{POKEBLOCK}を みると\n"
	.string "{JPN}ざらつきで ひょうかされてるのが\n"
	.string "{JPN}わかるでしょう\p"
	.string "{JPN}ざらつきの すうじが ひくいほど\n"
	.string "{JPN}よい {POKEBLOCK}なの これを\n"
	.string "{JPN}わすれちゃ だめよ!\p"
	.string "{JPN}よい {POKEBLOCK}は ざらつきが\n"
	.string "{JPN}ひくくて レベルが たかいの\p"
	.string "{JPN}ポケモンも よい {POKEBLOCK}なら\n"
	.string "{JPN}ふつうより たくさん たべられるわ\p"
	.string "{JPN}そして これが だいじ\p"
	.string "{JPN}なめらかな {POKEBLOCK}を つくりたいなら\n"
	.string "{JPN}ちがう しゅるいの きのみを\n"
	.string "{JPN}つかうのよ\p"
	.string "{JPN}けちっちゃ だめ きのみの しゅるい\n"
	.string "{JPN}が {POKEBLOCK}の なめらかさに\n"
	.string "{JPN}えいきょうするの\p"
	.string "{JPN}それから もうひとつ\p"
	.string "{JPN}きのみを まぜる ひとが おおいほど\n"
	.string "{JPN}{POKEBLOCK}は なめらかに なるの\p"
	.string "{JPN}だから ほかの ひとと はなしあって\n"
	.string "{JPN}いっしょに {POKEBLOCK}を\n"
	.string "{JPN}つくったほうが いいのよ\pよい {POKEBLOCK}を つくるのに\nしっておくことは だいたい\nこんな ところね\pみんなが あいする ポケモンと\nnamerakana {POKEBLOCK}と\nあたたかい かぞくが いれば\lせかいは もっと しあわせに なるわ\pがんばって!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "{JPN}つまが よつごを うんだときは\n"
	.string "{JPN}さすがに おどろいたよ\p"
	.string "{JPN}でも いまは みんなで あそんでる\n"
	.string "{JPN}すがたを みると うれしくなるね$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "{JPN}マルチバトルを やってるけど\n"
	.string "{JPN}ぜったい かつぞ!$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "{JPN}レコードコーナーで いろんなものを\n"
	.string "{JPN}まぜるのが すきなんだ\p"
	.string "{JPN}でも なにが まざるんだろう?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "{JPN}きのみブレンダーで すごい\n"
	.string "{JPN}{POKEBLOCK}を つくるぞ!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "{JPN}じぶんの ポケモンが どれだけ\n"
	.string "{JPN}つよいか じまんしたいから\l"
	.string "{JPN}コンテストに でるんだ$"

