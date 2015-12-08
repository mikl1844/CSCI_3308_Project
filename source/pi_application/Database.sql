CREATE TABLE IF NOT EXISTS `Users` (
`Name` varchar(10) NOT NULL,
`ID` int(1) NOT NULL auto_increment,
`Password` varchar(10) NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

INSERT INTO `Users` (`Name`, `ID`, `Password`) VALUES
	('Ryan',1,'abc123'),
	('Mitch',2,'password'),
	('A',3,'aaaaaa');

CREATE TABLE IF NOT EXISTS `House_DB` (
`ID` int(1) NOT NULL auto_increment,
`Temperature` int(1) NOT NULL,
`SmartLock` varchar(5) NOT NULL,
`LightRelay` varchar(3) NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

INSERT INTO `House_DB` (`ID`, `Temperature`, `SmartLock`,`LightRelay`) VALUES
        (1,75,'open','off'),
        (2,67,'close','off'),
        (3,72,'1234','off');

CREATE TABLE IF NOT EXISTS `House_Data` (
`Avg_Temp` int(1) NOT NULL,
`Current_Temp` int(1) NOT NULL,
`Avg_Humidity` int(1) NOT NULL,
`Current_Humidity` int(1) NOT NULL,
`Lock_Status` int(1) NOT NULL,
`Relay_Status` int(1) NOT NULL,
`Avg_Power` int(1) NOT NULL,
PRIMARY KEY (`Avg_Temp`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

INSERT INTO `House_Data` (`Avg_Temp`, `Current_Temp`, `Avg_Humidity`, `Current_Humidity`, `Lock_Status`, `Relay_Status`, `Avg_Power`) VALUES
        (0,0,0,0,0,0,0);

CREATE TABLE IF NOT EXISTS `History` (
`ID` int(1) NOT NULL auto_increment,
`Power` int(1) NOT NULL,
`Lock_Count` int(1) NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=7 ;

INSERT INTO `History` (`ID`, `Power`, `Lock_Count`) VALUES
        (1,0,0),
        (2,0,0),
        (3,0,0);
