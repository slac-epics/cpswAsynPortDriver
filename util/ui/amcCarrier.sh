source /afs/slac/g/lcls/epics/setup/go_NextGen_GUI.bash
caQtDM -macro "DEVICE=TEST" AmcCarrier.ui &
caQtDM -macro "DEVICE=TEST,PORT=AdcDebug[0]" graph.ui &
