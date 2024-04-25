CREATE DATABASE  IF NOT EXISTS `bankautomat` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `bankautomat`;
-- MySQL dump 10.13  Distrib 8.0.34, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: bankautomat
-- ------------------------------------------------------
-- Server version	8.2.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `idAccount` int NOT NULL AUTO_INCREMENT,
  `balance` decimal(10,2) DEFAULT NULL,
  `creditLimit` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`idAccount`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,7.22,1000.00),(2,109.00,1000.00),(3,272.00,0.00);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `idCard` varchar(20) NOT NULL,
  `Pin` varchar(150) DEFAULT NULL,
  `cardType` enum('DEBIT','CREDIT','BOTH') DEFAULT 'DEBIT',
  PRIMARY KEY (`idCard`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES ('0600062016','$2b$10$sXgq6xUiKUQijNqoWLJKL.rMlKhT.seAFZ.bgSJ335MBqe8aKFqQK','DEBIT'),('060006233','$2b$10$1MH9iAZDKnlLlFx2qmZNSOL6ytxcHw75ZWNZ00YqPqya8lHxgrKJG','CREDIT'),('0600064971','$2b$10$GWDZMizcoQK5Z0i1EjoIV.1jxR4zgsnho9d2bgoB6fwo5rJT0gGEC','BOTH'),('n-0600064971','$2b$10$DaHWFS8W6dySnW3awm63muam7Qqkt3eCbpGu0Njk4D.t4Kq4Z35VK','DEBIT'),('testi','$2b$10$q8ZrOPSISLCOGQr8/bRs5uAdtHL9qDRh9q4N/gY69EBdg2W4AYXN2',NULL),('testi2','$2b$10$BzXaik7NQsGUBAOpJ5jo6edkfLzpfCXm4RM2EfOoqxAfBaSvpdESu','CREDIT');
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cardaccount`
--

DROP TABLE IF EXISTS `cardaccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `cardaccount` (
  `idAccount` int DEFAULT NULL,
  `idCard` varchar(20) DEFAULT NULL,
  KEY `account_card_idx` (`idCard`),
  KEY `card_account_idx` (`idAccount`),
  CONSTRAINT `account_card` FOREIGN KEY (`idCard`) REFERENCES `card` (`idCard`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `card_account` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cardaccount`
--

LOCK TABLES `cardaccount` WRITE;
/*!40000 ALTER TABLE `cardaccount` DISABLE KEYS */;
INSERT INTO `cardaccount` VALUES (3,'0600062016'),(2,'060006233'),(1,'0600064971');
/*!40000 ALTER TABLE `cardaccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `idCustomer` int NOT NULL AUTO_INCREMENT,
  `fname` varchar(45) DEFAULT NULL,
  `lname` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idCustomer`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customeraccount`
--

DROP TABLE IF EXISTS `customeraccount`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customeraccount` (
  `IdCustomer` int DEFAULT NULL,
  `idAccount` int DEFAULT NULL,
  KEY `account_customer_idx` (`IdCustomer`),
  KEY `customer_account_idx` (`idAccount`),
  CONSTRAINT `account_customer` FOREIGN KEY (`IdCustomer`) REFERENCES `customer` (`idCustomer`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `customer_account` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customeraccount`
--

LOCK TABLES `customeraccount` WRITE;
/*!40000 ALTER TABLE `customeraccount` DISABLE KEYS */;
/*!40000 ALTER TABLE `customeraccount` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `idtransaction` int NOT NULL AUTO_INCREMENT,
  `idAccount` int DEFAULT NULL,
  `date` datetime DEFAULT NULL,
  `withdraw` varchar(45) DEFAULT NULL,
  `amount` int DEFAULT NULL,
  PRIMARY KEY (`idtransaction`),
  KEY `transaccount_idx` (`idAccount`),
  CONSTRAINT `transaccount` FOREIGN KEY (`idAccount`) REFERENCES `account` (`idAccount`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=18 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,NULL,'2024-04-02 00:00:00','1',500),(2,1,'2024-04-25 16:37:31','withdrawal',100),(3,2,'2024-04-25 16:37:43','withdrawal',100),(4,3,'2024-04-25 16:37:57','withdrawal',100),(5,3,'2024-04-25 17:07:46','withdrawal',20),(6,3,'2024-04-25 17:13:48','withdrawal',20),(7,1,'2024-04-25 17:25:44','withdrawal',25),(8,3,'2024-04-25 17:35:08','withdrawal',20),(9,2,'2024-04-25 17:37:14','withdrawal',25),(10,2,'2024-04-25 17:47:14','withdrawal',25),(11,2,'2024-04-25 17:58:16','withdrawal',25),(12,2,'2024-04-25 18:05:50','withdrawal',60),(13,2,'2024-04-25 18:06:54','withdrawal',60),(14,2,'2024-04-25 18:08:31','withdrawal',40),(15,2,'2024-04-25 18:09:57','withdrawal',40),(16,2,'2024-04-25 18:10:09','withdrawal',40),(17,2,'2024-04-25 18:10:14','withdrawal',40);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'bankautomat'
--
/*!50003 DROP PROCEDURE IF EXISTS `debit_withdrawal` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_withdrawal`(IN first_id INT, IN amount DOUBLE )
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE account SET balance = balance - amount WHERE idaccount = first_id AND balance >= amount;
  SET test1 = ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO transaction(idaccount, withdraw, amount, date) VALUES(first_id, 'withdrawal', amount, NOW());
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-04-25 18:41:51
