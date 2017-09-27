<?php

/**
 * @file
 * class EleveEleveWrapper
 */
module_load_include('inc', 'entity_entity', 'includes/eleve/eleve_sql');
module_load_include('php', 'wrappers_custom', 'includes/eleve/WdEleveWrapper');

class EleveEleveWrapper extends WdEleveWrapper {

    protected $entity_type = 'eleve';
    private static $bundle = 'eleve';

    /**
     * Create a new eleve eleve.
     *
     * @param array $values
     * @param string $language
     * @return EleveEleveWrapper
     */
    public static function create($values = array(), $language = LANGUAGE_NONE) {
        $values += array('entity_type' => 'eleve', 'bundle' => self::$bundle, 'type' => self::$bundle);
        $entity_wrapper = parent::create($values, $language);
        return new EleveEleveWrapper($entity_wrapper->value());
    }

    /**
     * Sets field_nom
     *
     * @param $value
     *
     * @return $this
     */
    public function setNom($value, $format = NULL) {
        $this->setText('field_nom', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_nom
     *
     * @return mixed
     */
    public function getNom($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_nom', $format, $markup_format);
    }

    /**
     * Sets field_prenom
     *
     * @param $value
     *
     * @return $this
     */
    public function setPrenom($value, $format = NULL) {
        $this->setText('field_prenom', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_prenom
     *
     * @return mixed
     */
    public function getPrenom($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_prenom', $format, $markup_format);
    }

    /**
     * Sets field_date_naiss
     *
     * @param $value
     *
     * @return $this
     */
    public function setDateNaiss($value) {
        $this->set('field_date_naiss', $value);
        return $this;
    }

    /**
     * Retrieves field_date_naiss
     *
     * @return mixed
     */
    public function getDateNaiss() {
        return $this->get('field_date_naiss');
    }

    /**
     * Sets field_adress
     *
     * @param $value
     *
     * @return $this
     */
    public function setAdress($value, $format = NULL) {
        $this->setText('field_adress', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_adress
     *
     * @return mixed
     */
    public function getAdress($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_adress', $format, $markup_format);
    }

    /**
     * Sets field_num_mat
     *
     * @param $value
     *
     * @return $this
     */
    public function setNumMat($value, $format = NULL) {
        $this->setText('field_num_mat', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_num_mat
     *
     * @return mixed
     */
    public function getNumMat($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_num_mat', $format, $markup_format);
    }

    /**
     * Sets field_tel
     *
     * @param $value
     *
     * @return $this
     */
    public function setTel($value, $format = NULL) {
        $this->setText('field_tel', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_tel
     *
     * @return mixed
     */
    public function getTel($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_tel', $format, $markup_format);
    }

    /**
     * Sets field_nom_pere
     *
     * @param $value
     *
     * @return $this
     */
    public function setNomPere($value, $format = NULL) {
        $this->setText('field_nom_pere', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_nom_pere
     *
     * @return mixed
     */
    public function getNomPere($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_nom_pere', $format, $markup_format);
    }

    /**
     * Sets field_profession_pere
     *
     * @param $value
     *
     * @return $this
     */
    public function setProfessionPere($value, $format = NULL) {
        $this->setText('field_profession_pere', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_profession_pere
     *
     * @return mixed
     */
    public function getProfessionPere($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_profession_pere', $format, $markup_format);
    }

    /**
     * Sets field_nom_mere
     *
     * @param $value
     *
     * @return $this
     */
    public function setNomMere($value, $format = NULL) {
        $this->setText('field_nom_mere', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_nom_mere
     *
     * @return mixed
     */
    public function getNomMere($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_nom_mere', $format, $markup_format);
    }

    /**
     * Sets field_profession_mere
     *
     * @param $value
     *
     * @return $this
     */
    public function setProfessionMere($value, $format = NULL) {
        $this->setText('field_profession_mere', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_profession_mere
     *
     * @return mixed
     */
    public function getProfessionMere($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_profession_mere', $format, $markup_format);
    }

    /**
     * Sets field_mpiraitampoho
     *
     * @param $value
     *
     * @return $this
     */
    public function setMpiraitampoho($value) {
        if (is_array($value)) {
            foreach ($value as $i => $v) {
                if ($v instanceof WdEleveWrapper) {
                    $value[$i] = $v->value();
                }
            }
        } else {
            if ($value instanceof WdEleveWrapper) {
                $value = $value->value();
            }
        }

        $this->set('field_mpiraitampoho', $value);
        return $this;
    }

    /**
     * Retrieves field_mpiraitampoho
     *
     * @return WdEleveWrapper
     */
    public function getMpiraitampoho() {
        $value = $this->get('field_mpiraitampoho');
        if (!empty($value)) {
            $value = new WdEleveWrapper($value);
        }
        return $value;
    }

    /**
     * Adds a value to field_mpiraitampoho
     *
     * @param $value
     *
     * @return $this
     */
    public function addToMpiraitampoho($value) {
        if ($value instanceof WdEleveWrapper) {
            $value = $value->value();
        }
        $existing_values = $this->get('field_mpiraitampoho');
        if (!empty($existing_values)) {
            foreach ($existing_values as $i => $existing_value) {
                if (!empty($existing_value) && entity_id('eleve', $existing_value) == entity_id('eleve', $value)) {
                    return $this;  // already here
                }
            }
        }
        $existing_values[] = $value;
        $this->set('field_mpiraitampoho', $existing_values);
        return $this;
    }

    /**
     * Removes a value from field_mpiraitampoho
     *
     * @param $value
     *   Value to remove.
     *
     * @return $this
     */
    function removeFromMpiraitampoho($value) {
        if ($value instanceof WdEleveWrapper) {
            $value = $value->value();
        }
        $existing_values = $this->get('field_mpiraitampoho');
        if (!empty($existing_values)) {
            foreach ($existing_values as $i => $existing_value) {
                if (!empty($existing_value) && entity_id('eleve', $existing_value) == entity_id('eleve', $value)) {
                    unset($existing_value[$i]);
                }
            }
        }
        $this->set('field_mpiraitampoho', array_values($existing_values));
        return $this;
    }

    /**
     * 
     * @param type $nom
     * @param type $prenom
     * @param type $date_naiss
     * @param type $lieu
     * @param type $adress
     * @param type $nom_pere
     * @param type $function_pere
     * @param type $nom_mere
     * @param type $function_mere
     */
    public static function addEleve($num_mat, $nom, $prenom = NULL, $sexe, $date_naiss, $lieu, $adress, $tel, $nom_pere = NULL, $function_pere = NULL, $nom_mere = NULL, $function_mere = NULL, $parent_adress = NULL, $nom_tuteur = NULL, $fonction_tutuer = NULL, $numtel_tutuer = NULL, $adress_tuteur = NULL, &$error_message = array()) {

        $return = 0;

        if ($num_mat != NULL && $nom != NULL && $sexe != NULL && $date_naiss != NULL && $lieu != NULL && $adress != NULL) {

            try {

                // jerena aloha raha mbola tsy misy mampiasa ny mun_mat
                $find = EleveEleveWrapper::getByNumMat($num_mat);

                if ($find == NULL) {

                    // jerena indray raha mbola tsy misy mitovy amin'ilay ankizy ao
                    $lookUpEleve = EleveEleveWrapper::lookUpEleve($nom, $prenom, $sexe, $date_naiss);

                    if ($lookUpEleve == NULL) {

                        $eleve = EleveEleveWrapper::create();

                        $eleve->setNumMat($num_mat);
                        $eleve->setTitle($num_mat);
                        $eleve->setNom($nom);
                        $eleve->setPrenom($prenom);
                        $eleve->setSex($sexe);
                        $eleve->setDateNaiss(strtotime($date_naiss));
                        $eleve->setLieu($lieu);
                        $eleve->setAdress($adress);
                        $eleve->setNomPere($nom_pere);
                        $eleve->setProfessionPere($function_pere);
                        $eleve->setNomMere($nom_mere);
                        $eleve->setProfessionMere($function_mere);
                        $eleve->setParentAdress($parent_adress);
                        $eleve->setTel($tel);
                        $eleve->setNomTuteur($nom_tuteur);
                        $eleve->setProfessionTuteur($fonction_tutuer);
                        $eleve->setNumTelTuteur($numtel_tutuer);
                        $eleve->setAdressTuteur($adress_tuteur);
                        $eleve->setPhoto(array(PUBLIC_FILE . '/' . FILE_PHOTO . '/' . variable_get('PHOTO_NAME', 'ELEVE.jpg')));

                        $eleve->save();

                        $return = $eleve->getId();
                    } else {
                        $link = l('élève', 'eleve/eleve/' . $lookUpEleve);
                        $error_message[] = t('Cet élève resemble à cet ' . $link);
                    }
                } else {
                    $error_message[] = t('Le numero matricule ' . $num_mat . ' existe déjà');
                }
            } catch (Exception $ex) {
                drupal_set_message($ex->getMessage());
            }
        }

        return $return;
    }

    /**
     * Sets field_lieu
     *
     * @param $value
     *
     * @return $this
     */
    public function setLieu($value, $format = NULL) {
        $this->setText('field_lieu', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_lieu
     *
     * @return mixed
     */
    public function getLieu($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_lieu', $format, $markup_format);
    }

    /**
     * 
     * @param type $num_mat
     * @return \EleveEleveWrapper
     */
    public static function getByNumMat($num_mat) {

        $eleve = NULL;

        if ($num_mat != NULL) {

            $query = _eleve_sql_get_by_num_mat($num_mat, $operator = '=');

            $result = db_query($query);

            while ($record = $result->fetchAssoc()) {
                $eleve = new EleveEleveWrapper($record['ID']);
            }
        }

        return $eleve;
    }

    /**
     * 
     * @param type $num_mat
     * @return \EleveEleveWrapper
     */
    public static function getById($id) {

        $eleve = NULL;

        if ($id != NULL) {

            $query = _eleve_sql_get_by_id($id);

            if ($query != NULL) {

                $result = db_query($query);

                while ($record = $result->fetchAssoc()) {
                    $eleve = new EleveEleveWrapper($record['ID']);
                }
            }
        }

        return $eleve;
    }

    /**
     * Maka ny sary hapetraka eo amin'ny form
     * 
     * @param type $width
     * @param type $height
     * @return type
     */
    public function getProfileImage($width = '150') {

        $profileImgPath = $this->getPhoto();

        if ($profileImgPath != NULL && file_exists($profileImgPath[0])) {

            $image_options = array(
                'path' => $profileImgPath[0],
                'alt' => $this->getNom() . ' ' . $this->getPrenom(),
                'title' => $this->getNom() . ' ' . $this->getPrenom(),
                'width' => $width,
                'attributes' => array('class' => 'profile-image', 'id' => ''),
            );

            return theme('image', $image_options);
        }
        return NULL;
    }

    /**
     * Sets field_photo
     *
     * @param $value
     *
     * @return $this
     */
    public function setPhoto($value, $format = NULL) {
        $this->setText('field_photo', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_photo
     *
     * @return mixed
     */
    public function getPhoto($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->get('field_photo');
    }

    /**
     * Sets field_sex
     *
     * @param $value
     *
     * @return $this
     */
    public function setSex($value) {
        $this->set('field_sex', $value);
        return $this;
    }

    /**
     * Retrieves field_sex
     *
     * @return mixed
     */
    public function getSex() {
        return $this->get('field_sex');
    }

    public static function lookUpEleve($nom, $prenom, $sex, $date_naiss) {

        $fullname1 = trim(str_replace(" ", "", $nom . $prenom));
        $fullname2 = trim(str_replace(" ", "", $prenom . $nom));

        $date_naiss = trim($date_naiss);

        $date_range = array();
        $query = " SELECT";
        $query .= " e.id as id";
        $query .= " , REPLACE(CONCAT(prenom.field_prenom_value,nom.field_nom_value),' ','') as FULLNAME";
        $query .= " FROM {eck_eleve} e";
        $query .= " JOIN {field_data_field_prenom}  prenom  ON e.id = prenom.entity_id  AND prenom.entity_type   = 'eleve' AND prenom.bundle  = 'eleve' AND prenom.deleted  = '0'";
        $query .= " JOIN {field_data_field_nom} nom ON e.id = nom.entity_id AND nom.entity_type  = 'eleve' AND nom.bundle = 'eleve' AND nom.deleted  = '0'";
        $query .= " JOIN {field_data_field_sex}       sex       ON e.id = sex.entity_id       AND sex.entity_type        = 'eleve' AND sex.bundle       = 'eleve' AND sex.deleted  = '0'";
        $query .= " JOIN {field_data_field_date_naiss} date_naiss ON e.id = date_naiss.entity_id AND date_naiss.entity_type  = 'eleve' AND date_naiss.bundle = 'eleve' AND date_naiss.deleted  = '0'";
        $query .= " WHERE ";
        $query .= " sex.field_sex_tid = :sex";
        if (trim($date_naiss) != '' && $date_naiss != NULL) {
            $query .= " AND date_naiss.field_date_naiss_value = :date_naiss ";
        }

        $query .= " HAVING FULLNAME LIKE :fullname1 OR FULLNAME LIKE :fullname2 ";

        $result = db_query($query, array(
            ':sex' => $sex,
            ':date_naiss' => $date_naiss,
            ':fullname1' => $fullname1,
            ':fullname2' => $fullname2,
        ));


        while ($record = $result->fetchAssoc()) {
            return $record['id'];
        }

        return NULL;
    }

    /**
     * Sets field_nom_tuteur
     *
     * @param $value
     *
     * @return $this
     */
    public function setNomTuteur($value, $format = NULL) {
        $this->setText('field_nom_tuteur', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_nom_tuteur
     *
     * @return mixed
     */
    public function getNomTuteur($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_nom_tuteur', $format, $markup_format);
    }

    /**
     * Sets field_profession_tuteur
     *
     * @param $value
     *
     * @return $this
     */
    public function setProfessionTuteur($value, $format = NULL) {
        $this->setText('field_profession_tuteur', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_profession_tuteur
     *
     * @return mixed
     */
    public function getProfessionTuteur($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_profession_tuteur', $format, $markup_format);
    }

    /**
     * Sets field_adress_tuteur
     *
     * @param $value
     *
     * @return $this
     */
    public function setAdressTuteur($value, $format = NULL) {
        $this->setText('field_adress_tuteur', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_adress_tuteur
     *
     * @return mixed
     */
    public function getAdressTuteur($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_adress_tuteur', $format, $markup_format);
    }

    /**
     * Sets field_num_tel_tuteur
     *
     * @param $value
     *
     * @return $this
     */
    public function setNumTelTuteur($value, $format = NULL) {
        $this->setText('field_num_tel_tuteur', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_num_tel_tuteur
     *
     * @return mixed
     */
    public function getNumTelTuteur($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_num_tel_tuteur', $format, $markup_format);
    }

    /**
     * Sets field_parent_adress
     *
     * @param $value
     *
     * @return $this
     */
    public function setParentAdress($value, $format = NULL) {
        $this->setText('field_parent_adress', $value, $format);
        return $this;
    }

    /**
     * Retrieves field_parent_adress
     *
     * @return mixed
     */
    public function getParentAdress($format = WdEntityWrapper::FORMAT_DEFAULT, $markup_format = NULL) {
        return $this->getText('field_parent_adress', $format, $markup_format);
    }

}
