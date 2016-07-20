#ifndef _SCANNER_DIALOG_H_
#define _SCANNER_DIALOG_H_

/**
 * \file scannerDialog.h
 * \brief Defines a scanner dialog class derived from BaseHostDialog
 *
 * \date Sep 17, 2010
 * \author Sergey Levi
 */

#include <QString>

#include "global.h"

#include "baseHostDialog.h"
#include "scannerThread.h"
#include "scannerParametersControlWidget.h"
#include "cloudViewDialog.h"
#include "scannercontrol.h"

#define UI_NAME_SCANNER "scanner"

class ScannerDialog : public BaseHostDialog
{
    Q_OBJECT

public:

    ScannerDialog();
    ScannerDialog(QString scannerPath);
    ~ScannerDialog();


    virtual void initParameterWidgets();
    virtual void createCalculator();
    virtual void connectFinishedRecalculation();

signals:
    void recordingTriggered();
    void recordingReset();

public slots:
    void openPathSelectDialog();
   // void toggleRecording();
  //  void resetRecording();
    void scanningStateChanged(ScannerThread::ScanningState);
    void scannerControlParametersChanged(QSharedPointer<ScannerParameters> params);

    virtual void processResult();

    void errorMessage(QString message);    
private:
    bool mIsScanning;
    ScannerControl scanCtrl;

    ScannerControl scanner;

    ScannerParametersControlWidgetAdv *mScannerParametersControlWidget;

    QSharedPointer<ScannerParameters> mScannerControlParams;

    CloudViewDialog *cloud = NULL;
    GraphPlotDialog *graph = NULL;
    GraphPlotDialog *graphConvolution = NULL;
    AdvancedImageWidget *addImage = NULL;
	AdvancedImageWidget *brightImage = NULL;
    AdvancedImageWidget *channelImage = NULL;
    AdvancedImageWidget *cornerImage = NULL;

};

#endif // _SCANNER_DIALOG_H_
