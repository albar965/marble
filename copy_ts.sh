#!/bin/bash

set -euo pipefail

LANGUAGES="fr it de pt_BR zh_CN"
SOURCEPATH=$APROJECTS/Extern/marble/poqm
DESTPATH=$APROJECTS/marble/translations
QTTOOLS=$HOME/Qt/$QT_VERSION/gcc_64/bin

for L in $LANGUAGES
do
  echo $L ====================
  po2ts ${SOURCEPATH}/${L}/marble_qt.po | sed 's_<comment>.*</comment>__g' | sed 's_<comment>.*__g' | sed 's_.*</comment>__g'> ${DESTPATH}/marble_${L}.ts
done


