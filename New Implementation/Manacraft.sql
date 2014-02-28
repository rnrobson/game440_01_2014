-- phpMyAdmin SQL Dump
-- version 3.4.11.1deb2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 28, 2014 at 02:27 AM
-- Server version: 5.5.33
-- PHP Version: 5.4.4-14+deb7u7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `Manacraft`
--

-- --------------------------------------------------------

--
-- Table structure for table `Elements`
--

CREATE TABLE IF NOT EXISTS `Elements` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Type` varchar(10) NOT NULL,
  `Weakness` varchar(10) NOT NULL,
  `Strength` varchar(10) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `Elements`
--

INSERT INTO `Elements` (`ID`, `Type`, `Weakness`, `Strength`) VALUES
(1, 'Fire', 'Water', 'Earth'),
(2, 'Water', 'Wind', 'Fire'),
(3, 'Earth', 'Fire', 'Wind'),
(4, 'Wind', 'Earth', 'Water'),
(5, 'Normal', '', '');

-- --------------------------------------------------------

--
-- Table structure for table `Minions`
--

CREATE TABLE IF NOT EXISTS `Minions` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Element` int(10) unsigned NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Level` int(10) unsigned NOT NULL,
  `Health` int(10) unsigned NOT NULL,
  `Damage` int(10) unsigned NOT NULL,
  `Armour` int(10) unsigned NOT NULL,
  `Speed` int(10) unsigned NOT NULL,
  `ManaPerSecond` int(10) unsigned NOT NULL,
  `Cost` int(10) unsigned NOT NULL,
  `SummonCost` int(10) unsigned NOT NULL,
  `UpgradeCost` int(10) unsigned NOT NULL,
  `ResearchCost` int(10) unsigned NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Element` (`Element`,`Name`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `Minions`
--

INSERT INTO `Minions` (`ID`, `Element`, `Name`, `Level`, `Health`, `Damage`, `Armour`, `Speed`, `ManaPerSecond`, `Cost`, `SummonCost`, `UpgradeCost`, `ResearchCost`) VALUES
(1, 1, 'Blazelings', 1, 4, 1, 2, 20, 0, 30, 0, 0, 0),
(2, 1, 'Blaze Elemental', 2, 16, 2, 4, 25, 1, 60, 0, 0, 0),
(3, 1, 'Fire Lords', 3, 33, 4, 8, 30, 33, 120, 0, 0, 0),
(4, 2, 'Sea Spray', 1, 10, 3, 2, 20, 0, 30, 0, 0, 0),
(5, 2, 'Water Elemental', 2, 40, 6, 3, 25, 1, 60, 0, 0, 0),
(6, 2, 'Tidal Lord', 3, 85, 12, 7, 30, 1, 120, 0, 0, 0),
(7, 3, 'Pebble', 1, 15, 3, 3, 15, 0, 30, 0, 0, 0),
(8, 3, 'Rock Elemental', 2, 55, 6, 5, 20, 1, 60, 0, 0, 0),
(9, 3, 'Granite Lord', 3, 120, 12, 9, 25, 1, 120, 0, 0, 0),
(10, 4, 'Gust', 1, 12, 3, 2, 25, 0, 30, 0, 0, 0),
(11, 4, 'Wind Elemental', 2, 48, 6, 4, 32, 1, 60, 0, 0, 0),
(12, 4, 'Storm Lord', 3, 100, 12, 8, 40, 1, 120, 0, 0, 0),
(13, 5, 'Garden Spider', 1, 10, 2, 1, 20, 0, 20, 0, 0, 0),
(14, 5, 'Tarantula', 2, 30, 4, 3, 20, 0, 40, 0, 0, 0),
(15, 5, 'Goliath Spider', 3, 90, 7, 7, 15, 1, 100, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Resistances`
--

CREATE TABLE IF NOT EXISTS `Resistances` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Type` varchar(10) NOT NULL,
  `WindResistance` int(11) NOT NULL,
  `FireResistance` int(11) NOT NULL,
  `WaterResistance` int(11) NOT NULL,
  `EarthResistance` int(11) NOT NULL,
  `NormalResistance` int(11) NOT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Dumping data for table `Resistances`
--

INSERT INTO `Resistances` (`ID`, `Type`, `WindResistance`, `FireResistance`, `WaterResistance`, `EarthResistance`, `NormalResistance`) VALUES
(1, 'Fire', 0, 25, -25, 0, 0),
(2, 'Water', -25, 0, 25, 0, 0),
(3, 'Earth', 0, -25, 0, 25, 0),
(4, 'Wind', 25, 0, 0, -25, 0),
(5, 'Normal', 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `Towers`
--

CREATE TABLE IF NOT EXISTS `Towers` (
  `ID` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Element` int(10) unsigned NOT NULL,
  `Name` varchar(20) NOT NULL,
  `Damage` int(10) unsigned NOT NULL,
  `Range` int(10) unsigned NOT NULL,
  `FiringRate` int(10) unsigned NOT NULL,
  `AttackType` varchar(20) NOT NULL,
  `Cost` int(10) unsigned NOT NULL,
  `SummonCost` int(10) unsigned NOT NULL,
  `UpgradeCost` int(10) unsigned NOT NULL,
  `ResearchCost` int(10) unsigned NOT NULL,
  `SellPrice` int(10) unsigned NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE KEY `Element` (`Element`,`Name`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Dumping data for table `Towers`
--

INSERT INTO `Towers` (`ID`, `Element`, `Name`, `Damage`, `Range`, `FiringRate`, `AttackType`, `Cost`, `SummonCost`, `UpgradeCost`, `ResearchCost`, `SellPrice`) VALUES
(1, 1, 'Flame', 3, 5, 1, 'SingleTarget', 50, 0, 0, 0, 0),
(2, 1, 'Fireball', 7, 3, 0, 'GroundTarget-AOE', 120, 0, 0, 0, 0),
(3, 1, 'Igniter', 5, 5, 1, 'SingleTarget', 100, 0, 0, 0, 0),
(4, 2, 'Water Blast', 3, 5, 1, 'SingleTarget', 50, 0, 0, 0, 0),
(5, 2, 'Tidal Wave', 2, 3, 1, 'Cone-AOE', 120, 0, 0, 0, 0),
(6, 2, 'Frost Beam', 6, 4, 2, 'SingleTarget', 100, 0, 0, 0, 0),
(7, 3, 'Rock Shard', 4, 4, 1, 'SingleTarget', 50, 0, 0, 0, 0),
(8, 3, 'Earthquake', 6, 2, 1, 'PointBlank-AOE', 120, 0, 0, 0, 0),
(9, 3, 'Boulder', 9, 4, 1, 'SingleTarget', 100, 0, 0, 0, 0),
(10, 4, '50', 2, 4, 2, 'SingleTarget', 50, 0, 0, 0, 0),
(11, 4, 'Lightning', 3, 5, 1, 'Chain-AOE', 120, 0, 0, 0, 0),
(12, 4, 'Wind Slash', 6, 4, 2, 'SingleTarget', 100, 0, 0, 0, 0),
(13, 5, 'Arrow', 2, 4, 2, 'SingleTarget', 40, 0, 0, 0, 0),
(14, 5, 'Cannon', 4, 3, 1, 'AOE', 90, 0, 0, 0, 0),
(15, 5, 'Ballista', 5, 5, 2, 'SingleTarget', 80, 0, 0, 0, 0);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Minions`
--
ALTER TABLE `Minions`
  ADD CONSTRAINT `Minions_ibfk_1` FOREIGN KEY (`Element`) REFERENCES `Elements` (`ID`);

--
-- Constraints for table `Resistances`
--
ALTER TABLE `Resistances`
  ADD CONSTRAINT `Resistances_ibfk_1` FOREIGN KEY (`ID`) REFERENCES `Elements` (`ID`);

--
-- Constraints for table `Towers`
--
ALTER TABLE `Towers`
  ADD CONSTRAINT `Towers_ibfk_1` FOREIGN KEY (`Element`) REFERENCES `Elements` (`ID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
