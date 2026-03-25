BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "{JPN}えへへ!\n"
	.string "{JPN}わたし ポケモンの きもちが\n"
	.string "{JPN}わかるの!\p"
	.string "{JPN}おねがい!\nあなたの ポケモンを\nみせて!$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "{JPN}ぶー!\n"
	.string "{JPN}けちんぼ!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても たたかうのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると やりかえすの!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると しんぱいするの!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても たたかうのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}でも いたくなると やりかえすの!$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると しんぱいするの!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても たたかうのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると やりかえすの!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると しんぱいするの!$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても こっそりするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると こっそりするの!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても たたかうのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても こっそりするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると しんぱいするの!$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}いたくても しんぱいするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}でも いたくなると こっそりするの!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}いたくても しんぱいするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは こっそりするのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}いたくても こっそりするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}いたくても しんぱいするのよ!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}でも いたくなると やりかえすの!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは たたかうのが\n"
	.string "{JPN}すきって いってるわ!\l"
	.string "{JPN}でも いたくなると こっそりするの!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "{JPN}ふむふむ...\p"
	.string "{JPN}このこは じぶんの ことを\n"
	.string "{JPN}きにかけるって いってるわ!\l"
	.string "{JPN}でも いたくなると こっそりするの!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "{JPN}それは むり! タマゴは\n"
	.string "{JPN}ねむってるもの!\nはなせないよ!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "{JPN}なんて すてきなの!\n"
	.string "{JPN}あの おじょうさんは ポケモンの\l"
	.string "{JPN}きもちが わかるって いってるわ!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "{JPN}あの ちいさな おんなのこが\n"
	.string "{JPN}なにか しんこくな ことを\nいってる きが するの$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "{JPN}しってるの!\p"
	.string "{JPN}あの ちいさな おんなのこは\n"
	.string "{JPN}あかい いえで よく\nあそんでるのよ!$"

