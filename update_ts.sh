#!/bin/bash

set -euo pipefail

LANGUAGES="fr it de pt_BR zh_CN"
SOURCEPATH=$APROJECTS/Extern/marble/poqm
MARBLEPATH=$APROJECTS/marble
DESTPATH=$APROJECTS/marble/translations
QTTOOLS=$HOME/Qt/$QT_VERSION/gcc_64/bin

for L in $LANGUAGES
do
  echo $L ====================
  $QTTOOLS/lupdate ${MARBLEPATH} -disable-heuristic similartext -target-language ${L} -ts ${DESTPATH}/marble_${L}.ts
  $QTTOOLS/lrelease ${DESTPATH}/marble_${L}.ts
done


