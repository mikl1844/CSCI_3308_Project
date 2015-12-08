CREATE TABLE IF NOT EXISTS `Users` (
`ID` int NOT NULL auto_increment,
`Username` varchar(16) NOT NULL,
`Start_time` varchar(6) NOT NULL,
`Stop_time` varchar(6) NOT NULL,
`Temperature` int NOT NULL,
PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1;
