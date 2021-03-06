; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "局域网内电子文档管理平台（服务端）"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "沈鑫楠"
#define MyAppExeName "FileManagement_Admin.exe"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{C43B2A4D-953A-4424-BDD4-272271C00E60}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
LicenseFile=G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\license.txt
InfoBeforeFile=G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\README.MD
InfoAfterFile=G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\GUIDE.MD
OutputDir=G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\setup
OutputBaseFilename=FileManagement_admin_setup
SetupIconFile=G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\Admin.ico
Password=admin123456
Compression=lzma
SolidCompression=yes

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"
Name: "brazilianportuguese"; MessagesFile: "compiler:Languages\BrazilianPortuguese.isl"
Name: "catalan"; MessagesFile: "compiler:Languages\Catalan.isl"
Name: "corsican"; MessagesFile: "compiler:Languages\Corsican.isl"
Name: "czech"; MessagesFile: "compiler:Languages\Czech.isl"
Name: "danish"; MessagesFile: "compiler:Languages\Danish.isl"
Name: "dutch"; MessagesFile: "compiler:Languages\Dutch.isl"
Name: "finnish"; MessagesFile: "compiler:Languages\Finnish.isl"
Name: "french"; MessagesFile: "compiler:Languages\French.isl"
Name: "german"; MessagesFile: "compiler:Languages\German.isl"
Name: "greek"; MessagesFile: "compiler:Languages\Greek.isl"
Name: "hebrew"; MessagesFile: "compiler:Languages\Hebrew.isl"
Name: "hungarian"; MessagesFile: "compiler:Languages\Hungarian.isl"
Name: "italian"; MessagesFile: "compiler:Languages\Italian.isl"
Name: "japanese"; MessagesFile: "compiler:Languages\Japanese.isl"
Name: "norwegian"; MessagesFile: "compiler:Languages\Norwegian.isl"
Name: "polish"; MessagesFile: "compiler:Languages\Polish.isl"
Name: "portuguese"; MessagesFile: "compiler:Languages\Portuguese.isl"
Name: "russian"; MessagesFile: "compiler:Languages\Russian.isl"
Name: "scottishgaelic"; MessagesFile: "compiler:Languages\ScottishGaelic.isl"
Name: "serbiancyrillic"; MessagesFile: "compiler:Languages\SerbianCyrillic.isl"
Name: "serbianlatin"; MessagesFile: "compiler:Languages\SerbianLatin.isl"
Name: "slovenian"; MessagesFile: "compiler:Languages\Slovenian.isl"
Name: "spanish"; MessagesFile: "compiler:Languages\Spanish.isl"
Name: "turkish"; MessagesFile: "compiler:Languages\Turkish.isl"
Name: "ukrainian"; MessagesFile: "compiler:Languages\Ukrainian.isl"

[Tasks]
Name: "desktopicon"; Description: "创建桌面快捷方式"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked


[Files]
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\FileManagement_Admin.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\filetype"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\filetype\*"; DestDir: "{app}\filetype"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\Admin.ico"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\FileManagement_Admin.exe.config"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\FileManagement_Admin.pdb"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\GUIDE.MD"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\license.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\main.jpg"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\FileManagement_Admin\bin\Release\README.MD"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\endserver.bat"; DestDir: "{app}"; Flags: ignoreversion
Source: "G:\实验\毕业设计\project\FileManagement_Admin\局域网内电子文档管理平台（服务端）- 操作指南.pdf"; DestDir: "{app}"; Flags: ignoreversion
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent

