-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 07, 2014 at 01:17 AM
-- Server version: 5.5.33
-- PHP Version: 5.4.4-14+deb7u7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `dbtest`
--

-- --------------------------------------------------------

--
-- Table structure for table `Elements`
--

CREATE TABLE IF NOT EXISTS `Elements` (
  `ID` int(4) unsigned zerofill NOT NULL DEFAULT '0000',
  `Type` varchar(15) DEFAULT NULL,
  `Weakness` varchar(15) DEFAULT NULL,
  `Strength` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Type` (`Type`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Minion`
--

CREATE TABLE IF NOT EXISTS `Minion` (
  `ID` int(4) NOT NULL DEFAULT '0',
  `Name` varchar(15) DEFAULT NULL,
  `XPos` float NOT NULL,
  `YPos` float NOT NULL,
  `Cost` int(4) DEFAULT NULL,
  `Damage` int(4) DEFAULT NULL,
  `AttackRange` int(4) DEFAULT NULL,
  `FiringRate` int(4) DEFAULT NULL,
  `DPS` int(6) DEFAULT NULL,
  `AttackType` varchar(15) DEFAULT NULL,
  `Element` varchar(15) DEFAULT NULL,
  `SellAmount` int(6) DEFAULT NULL,
  `SummonCost` int(6) DEFAULT NULL,
  `UpgradeCost` int(6) DEFAULT NULL,
  `ResearchCost` int(6) DEFAULT NULL,
  `Resistances` varchar(15) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Resistances` (`Resistances`),
  UNIQUE KEY `Element` (`Element`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Player`
--

CREATE TABLE IF NOT EXISTS `Player` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `Name` varchar(10) NOT NULL,
  `Health` int(3) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `Player`
--

INSERT INTO `Player` (`ID`, `Name`, `Health`) VALUES
(1, 'Greg', 100);

-- --------------------------------------------------------

--
-- Table structure for table `Projectile`
--

CREATE TABLE IF NOT EXISTS `Projectile` (
  `XPos` float NOT NULL,
  `YPos` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Resistances`
--

CREATE TABLE IF NOT EXISTS `Resistances` (
  `ID` int(4) NOT NULL DEFAULT '0',
  `Type` varchar(15) DEFAULT NULL,
  `WindResistance` varchar(15) DEFAULT NULL,
  `FireResistance` varchar(15) DEFAULT NULL,
  `WaterResistance` varchar(15) DEFAULT NULL,
  `EarthResistance` varchar(15) DEFAULT NULL,
  `NormalResistance` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Type` (`Type`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Tower`
--

CREATE TABLE IF NOT EXISTS `Tower` (
  `ID` int(4) NOT NULL DEFAULT '0',
  `Name` varchar(15) DEFAULT NULL,
  `Cost` int(4) DEFAULT NULL,
  `Damage` int(4) DEFAULT NULL,
  `AttackRange` int(4) DEFAULT NULL,
  `FiringRate` int(4) DEFAULT NULL,
  `DPS` int(6) DEFAULT NULL,
  `AttackType` varchar(15) DEFAULT NULL,
  `Element` varchar(15) DEFAULT NULL,
  `SellAmount` int(6) DEFAULT NULL,
  `SummonCost` int(6) DEFAULT NULL,
  `UpgradeCost` int(6) DEFAULT NULL,
  `ResearchCost` int(6) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Element` (`Element`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Minion`
--
ALTER TABLE `Minion`
  ADD CONSTRAINT `Minion_ibfk_2` FOREIGN KEY (`Element`) REFERENCES `Elements` (`Type`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `Minion_ibfk_1` FOREIGN KEY (`Resistances`) REFERENCES `Resistances` (`Type`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Resistances`
--
ALTER TABLE `Resistances`
  ADD CONSTRAINT `Resistances_ibfk_1` FOREIGN KEY (`Type`) REFERENCES `Elements` (`Type`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `Tower`
--
ALTER TABLE `Tower`
  ADD CONSTRAINT `Tower_ibfk_1` FOREIGN KEY (`Element`) REFERENCES `Elements` (`Type`) ON DELETE NO ACTION ON UPDATE NO ACTION;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
