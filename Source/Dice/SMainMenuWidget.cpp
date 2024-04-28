#include "SMainMenuWidget.h"



void SMainMenuWidget::Construct(const FArguments& InArgs)
{
    // Build the widget layout
    ChildSlot
        [
            SNew(SVerticalBox)

                // GameStart Button
                + SVerticalBox::Slot()
                .Padding(10.0f)
                [
                    SNew(SButton)
                        .Text(NSLOCTEXT("MainMenu", "GameStart", "Game Start"))
                       //.OnClicked(this, &SMainMenuWidget::OnGameStartClicked)
                        [
                            SNew(STextBlock)
                                .Text(NSLOCTEXT("MainMenu", "GameStart", "Game Start"))
                        ]
                ]

                // Setting Button
                + SVerticalBox::Slot()
                .Padding(10.0f)
                [
                    SNew(SButton)
                        .Text(NSLOCTEXT("MainMenu", "Setting", "Setting"))
                        //.OnClicked(this, &SMainMenuWidget::OnSettingClicked)
                        [
                            SNew(STextBlock)
                                .Text(NSLOCTEXT("MainMenu", "Setting", "Setting"))
                        ]
                ]

                // Exit Button
                + SVerticalBox::Slot()
                .Padding(10.0f)
                [
                    SNew(SButton)
                        .Text(NSLOCTEXT("MainMenu", "Exit", "Exit"))
                        //.OnClicked(this, &SMainMenuWidget::OnExitClicked)
                        [
                            SNew(STextBlock)
                                .Text(NSLOCTEXT("MainMenu", "Exit", "Exit"))
                        ]
                ]
        ];
}

// Button click handlers
