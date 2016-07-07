<?php

/**
 * @file
 *  Alter some islandora_batch default views.
 */

/**
 * Implements hook_views_default_views().
 */
function upei_roblib_batch_cleanup_views_default_views_alter(&$views) {
  $handler =& $views['islandora_batch_sets']->display['default']->handler;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['empty'] = TRUE;
  $handler->display->display_options['footer']['area']['content'] = 'Completed sets will automatically be deleted if they are older then a week.';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
}